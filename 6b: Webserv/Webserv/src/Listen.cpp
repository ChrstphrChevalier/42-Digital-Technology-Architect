/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:02:31 by waziz             #+#    #+#             */
/*   Updated: 2024/07/01 20:51:54 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Listen.hpp"

volatile sig_atomic_t Sig = 0;

/*----------------------------------------------------------------------*/
/*            			Socket Initialisation							*/
//																		//
/*						|	socketOptions 	|							*/
/*						|	bindAndListen	|							*/
//																		//
/*						  - createSockets -								*/
/*----------------------------------------------------------------------*/

static void	socketOptions(int socket_fd, bool *isValid) {
	int opt = 1;
	cout << PURP << "Options" << CYAN << " -> " << RST;
	if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
		cout << ITAL << "SO_REUSEADDR" << RST << PURP << " : " << REDD << "failed" << GRY1 << " | " << RST;
		(*isValid) = false;
	}
	else
		cout << ITAL << "SO_REUSEADDR" << RST << PURP << " : " << LIME << "success" << GRY1 << " | " << RST;

	int flags = fcntl(socket_fd, F_GETFL, 0);
	if (flags == -1)
		(*isValid) = false;
	
	if (fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
		cout << ITAL << "O_NONBLOCK" << RST << PURP << " : " << REDD << "failed" << RST << endl;;
		(*isValid) = false;
	}
	else
		cout << ITAL << "O_NONBLOCK" << RST << PURP << " : " << LIME << "succes" << RST << endl;;
}

static void	bindAndListen(int socket_fd, int port, bool *isValid) {
	struct sockaddr_in	addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	bool	available = false;

	if (bind(socket_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		cout << PURP << ITAL << "Availability" << RST << CYAN << " -> " << REDD << "KO" << RST << endl;
		(*isValid) = false;
	}
	else {
		cout << PURP << ITAL << "Availability" << RST << CYAN << " -> " << LIME << "OK" << RST << endl;
		available = true;
	}
	
	if (listen(socket_fd, 255) < 0 || !available) {
		cout << PURP << ITAL << "Network" << RST << CYAN << " -> " << REDD << "KO" << RST << endl;
		(*isValid) = false;
	}
	else
		cout << PURP << ITAL << "Network" << RST << CYAN << " -> " << RST;
		cout << addr.sin_port << GRY1 << " : " << LIME << "OK" << RST << endl;
}

/* Function Master */
void	Listen::createSockets(const vector<Server>& servers) {
	bool	validServer = false;
	for (vector<Server>::const_iterator its = servers.begin(); its != servers.end(); its++) {
		if (its != servers.begin())
			cout << endl;
		cout << GRY1 << "SERVER -> " << BLUE << its->getName() << RST;
		cout << CYAN << " : " << RST << ITAL << "initilization..." << RST << endl;
		int	countPort = 0;
		const vector<int>& ports = its->getPorts();
		for (vector<int>::const_iterator itp = ports.begin(); itp != ports.end(); itp++) {
			bool	isValid = true;
			cout << CYAN << "port" << BLUE << " : " << RST << *itp << endl;
			int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
			if (socket_fd < 0)
				throw runtime_error("Failed to create socket");
			socketOptions(socket_fd, &isValid);
			bindAndListen(socket_fd, *itp, &isValid);
			if (isValid) {
				cout << PURP << ITAL << "Socket_fd" << RST << CYAN << " -> " << YLLW << socket_fd << RST << endl;
				_sockets.push_back(socket_fd);
				_whichServ.insert(make_pair(socket_fd, ref(*its)));
				countPort++;
			}
			else 
				close(socket_fd);
			if (itp != ports.end() - 1)
				cout << endl;
		}
		if (countPort > 0) {
			cout << BLUE << its->getName() << RST << " : " << LIME << "actived" << RST << endl;
			validServer = true;
		}
		else
			cout << BLUE << its->getName() << RST << " : " << REDD << "inactive" << RST << endl;
	}
	if (!validServer)
		throw runtime_error("No server enabled");
	cout << endl;
}

/*----------------------------------------------------------------------*/
/*            			KQUEUE Initialisation							*/
//																		//
/*							- initKqueue -								*/
/*----------------------------------------------------------------------*/

void Listen::initKqueue() {
	cout << GRY1 << ITAL << "KQUEUE : " << RST << ITAL << "initialization..." << RST << endl;
	_kqueueFd = kqueue();
	if (_kqueueFd == -1)
		throw runtime_error("Failed to create kqueue");
	cout << CYAN << "kqueue_fd" << RST << " : " << YLLW << _kqueueFd << RST << endl;
	
	struct kevent ev_set;
	for (vector<int>::const_iterator it = _sockets.begin(); it != _sockets.end(); it++) {
		EV_SET(&ev_set, *it, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);	
		if (kevent(_kqueueFd, &ev_set, 1, NULL, 0, NULL) < 0) {
			cout << PURP << "socket_fd " << GRY2 << "-> " << YLLW << *it << CYAN;
			cout << " | " << RST << "EVFILT_READ" << GRY1 << " : " << RST;
			throw runtime_error("Failed to add socket to kqueue");
		}
		cout << PURP << "socket_fd " << GRY2 << "-> " << YLLW << *it << CYAN;
		cout << " | " << RST << "EVFILT_READ" << GRY1 << " : " << LIME << "connected" << RST <<  endl;
	}
}

/*----------------------------------------------------------------------*/
/*            				Signal Gestion								*/
/*																		*/
/*								signal 									*/
/*							 setup_signal								*/
/*----------------------------------------------------------------------*/

void Listen::signal(int sig) {
    if (sig == SIGINT || sig == SIGTERM || sig == SIGQUIT) {
        Sig = 1;
    }
}

void Listen::setup_signal() {
    struct sigaction sa;
    sa.sa_handler = signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    sigaction(SIGQUIT, &sa, NULL);
}

/*----------------------------------------------------------------------*/
/*            				Event Gestion	 							*/
//																		//
/*						|	  addClient		|							*/
/*						|	recept_request	|							*/
/*						|	send_response	|							*/
//																		//
/*							   - run -									*/
/*----------------------------------------------------------------------*/

int	Listen::addClient(int *ev_fd, int *mem_fd) {
	(*mem_fd) = (*ev_fd);
	struct sockaddr_in client_addr;
	socklen_t client_len = sizeof(client_addr);
	int client_fd = accept((*ev_fd), (struct sockaddr*)&client_addr, &client_len);
	if (client_fd < 0) {
		cout << REDD << "Error on accept" << RST << endl;
		return (0);
	}

	int flags = fcntl(client_fd, F_GETFL, 0);
	if (flags < 0) {
		cout << REDD << "Error getting client_fd flags" << RST << endl;
		close(client_fd);
		return (0);
	}

	if (fcntl(client_fd, F_SETFL, flags | O_NONBLOCK) < 0) {
		cout << REDD << "Error setting client_fd to non-blocking" << RST << endl;
		close(client_fd);
		return (0);
	}

	cout << CYAN << ITAL << "New connection" << RST << GRY1 << " -> " LIME << "accepted" << RST;
	cout << GRY1 << ITAL << " on " << PURP << "socket_fd" << GRY1 << " : " << YLLW << mem_fd << RST;
	cout << GRY1 << ITAL << " by " << PURP << "client_fd" << GRY1 << " : " << YLLW << client_fd << RST << endl;

	struct kevent ev_set;
	EV_SET(&ev_set, client_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	if (kevent(_kqueueFd, &ev_set, 1, NULL, 0, NULL) < 0) {
		cout << REDD << "Failed to add EVFILT_READ for client_fd to kqueue" << RST << endl;
		close(client_fd);
	}

	EV_SET(&ev_set, client_fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
	if (kevent(_kqueueFd, &ev_set, 1, NULL, 0, NULL) < 0) {
		cerr << "Failed to add EVFILT_WRITE for client_fd to kqueue" << endl;
		close(client_fd);
	}
	return (1);
}

void	Listen::recept_request(int ev_fd, int mem_fd, map<int, string>& req_buffer, \
						map<int, ssize_t>& req_length, map<int, pair<istringstream*, ifstream*> >& rs) {
	char buffer[1024];
	memset(buffer, 0, sizeof(buffer));
	ssize_t bytesRead = read(ev_fd, buffer, sizeof(buffer) - 1);
	if (bytesRead < 0) {
		cout << "Error reading from client_fd" << endl;
		req_buffer.erase(ev_fd);
		req_length.erase(ev_fd);
		close(ev_fd);
	} else if (bytesRead == 0) {
		cout << PURP << "client_fd" << RST << GRY1 << " : ";
		cout << YLLW << ev_fd << GRY1 << " -> " << REDD << "disconnected" << RST << endl;
		req_buffer.erase(ev_fd);
		req_length.erase(ev_fd);
		close(ev_fd);
	} else {
		buffer[bytesRead] = '\0';
		req_buffer[ev_fd] += buffer;

		if (req_buffer[ev_fd].find("\r\n\r\n") != string::npos) {
			size_t contentLength = req_buffer[ev_fd].find("Content-Length:");
			if (contentLength != string::npos) {
				size_t endLinePos = req_buffer[ev_fd].find("\r\n", contentLength);
				string contentLengthStr = req_buffer[ev_fd].substr(contentLength + 15, endLinePos - contentLength - 15);
				req_length[ev_fd] = stoi(contentLengthStr);
			} else
				req_length[ev_fd] = 0;
		}

		if (req_buffer[ev_fd].find("\r\n\r\n") != string::npos
			&& req_buffer[ev_fd].size() >= req_buffer[ev_fd].find("\r\n\r\n") + 4 + req_length[ev_fd]) {
			for (map<int, const Server&>::const_iterator ita = _whichServ.begin(); ita != _whichServ.end(); ita++) {
				if (ita->first == mem_fd) {
					const Server& tmp = ita->second;

					_req = new Request(tmp, req_buffer[ev_fd], ev_fd);

					if (_req->isFile()) {
						istringstream *iss = new istringstream(_req->_respond->getHeader());
						ifstream *ifs = new ifstream(_req->_respond->getFile());
						rs.insert(make_pair(ev_fd, make_pair(iss, ifs)));
					} else {
						istringstream *iss = new istringstream(_req->_respond->getResp());
						ifstream *ifs = new ifstream();
						rs.insert(make_pair(ev_fd, make_pair(iss, ifs)));
					}

					delete _req;
					_req = NULL;
					break ;
				}
			}
			req_buffer.erase(ev_fd);
			req_length.erase(ev_fd);
		}
	}
}

void	Listen::send_response(int ev_fd, map<int, pair<istringstream*, ifstream*> >& rs) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    pair<istringstream*, ifstream*>& streams = rs.find(ev_fd)->second;
    streamsize bytes_read = 0;

    if (!streams.first->eof()) {
        streams.first->read(buffer, sizeof(buffer));
        bytes_read = streams.first->gcount();
    }

    if (bytes_read < static_cast<streamsize>(sizeof(buffer)) && streams.second->is_open() && !streams.second->eof()) {
        streams.second->read(buffer + bytes_read, sizeof(buffer) - bytes_read);
        bytes_read += streams.second->gcount();
    }

    if (bytes_read > 0) {
        ssize_t bytes_written = write(ev_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            cerr << "Error writing to client_fd" << endl;
            rs.erase(ev_fd);
            close(ev_fd);
            return;
        }
    }

    if (streams.first->eof() && (streams.second->eof() || !streams.second->is_open())) {
		cout << CYAN << ITAL << "Response sent" << GRY1 << ITAL << " to " << RST << "(" << PURP << "client_fd" << GRY1 << " : " << YLLW << ev_fd << RST << ")" << endl;
		cout << endl;
		delete streams.first;
		delete streams.second;
        rs.erase(ev_fd);
        close(ev_fd);
    }
}



/* Function Master */
void Listen::run() {
	setup_signal();
    map<int, string> 	req_buffer;
    map<int, ssize_t> 	req_length;
	map<int, string>	resp_buffer;
	map<int, pair<istringstream*, ifstream*> >	rs;
    int mem_fd;
    struct kevent ev_list[1500];

    cout << CYAN << ITAL << "Running Webserv..." << RST << endl;
    cout << endl;

    while (!Sig) {
        int nev = kevent(_kqueueFd, NULL, 0, ev_list, 1500, NULL);
        if (nev < 0 && !Sig)
            throw runtime_error("kevent error");

        for (int i = 0; i < nev; i++) {
            int ev_fd = ev_list[i].ident;

			if (ev_list[i].filter == EVFILT_READ) {
				if (find(_sockets.begin(), _sockets.end(), ev_fd) != _sockets.end()) {
					if (addClient(&ev_fd, &mem_fd) == 0 )
						continue ;
				} else
					recept_request(ev_fd, mem_fd, req_buffer, req_length, rs);
			} else if (ev_list[i].filter == EVFILT_WRITE) {
					if (rs.find(ev_fd) != rs.end())
						send_response(ev_fd, rs);
			}
		}
	}
	for (map<int, string>::iterator itreq = req_buffer.begin(); itreq != req_buffer.end(); itreq++)
		close(itreq->first);
	for (map<int, string>::iterator itresp = resp_buffer.begin(); itresp != resp_buffer.end(); itresp++)
		close(itresp->first);
	req_buffer.clear();
	req_length.clear();
	resp_buffer.clear();
	rs.clear();
}

/*----------------------------------------------------------------------*/
/*            			Constructor Listen								*/
/*----------------------------------------------------------------------*/

Listen::Listen(const vector<Server>& servers) : _req(NULL) {
	createSockets(servers);
	initKqueue();
	cout << endl;
	run();
}

/*----------------------------------------------------------------------*/
/*            			Desstructor Listen								*/
/*----------------------------------------------------------------------*/

Listen::~Listen() {
	if (_req)
		delete _req;
	for (vector<int>::iterator it = _sockets.begin(); it != _sockets.end(); it++)
		close(*it);
	close(_kqueueFd);
	_sockets.clear();
	_whichServ.clear();
}