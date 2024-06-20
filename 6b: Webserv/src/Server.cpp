/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:01:26 by waziz             #+#    #+#             */
/*   Updated: 2024/06/19 12:55:35 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Server.hpp"

static void	trim(string *str) {
	(*str).erase(0, (*str).find_first_not_of(" \t"));
    (*str).erase((*str).find_last_not_of(" \t") + 1);
}

static	bool	validNum(string num, int option) {
	if (option == 0) {
		if (num.length() > 5)
			return false;
	}
	else {
		if (num.length() > 9)
			return false;
	}
	for (string::iterator it = num.begin(); it != num.end(); it++)
		if (!isdigit(*it))
			return false;
	return true;
}

static bool validPath(const string& path) {
	struct stat info;
	return stat(path.c_str(), &info) == 0;
}

static bool validMethod(const string& method) {
	return method == "GET" || method == "POST" || method == "DELETE";
}

static bool validSysPath(const string& path) {
	return access(path.c_str(), X_OK) == 0;
}

void	Server::configServ(const vector<pair<string, string> >& config) {
	vector<pair<string, string> > c = config;
	vector<pair<string, string> >::iterator it = c.begin();
	_maxBodySize = -1;
	while (it != c.end()) {
		if (!it->first.empty()) {
			if (it->first == "host" && !it->second.empty()) {
				if (it->second == "localhost" || it->second == "127.0.0.1")
					_host = it->second;
			}
			else if (it->first == "root" && !it->second.empty()) {
				if (validPath(it->second))
					_root = it->second;
			}
			else if (it->first == "server_name" && !it->second.empty())
				_serverName = it->second;
			else if (it->first == "port") {
				if (validNum(it->second, 0))
					_port.push_back(stoi(it->second));
			}
			else if (it->first == "max_body_size" && !it->second.empty()) {
				if (validNum(it->second, 1))
					_maxBodySize = stoll(it->second);
			}
			else if (it->first == "default_page" && !it->second.empty()) {
				if (validPath(it->second))
					_default_page = it->second;
			}
			else if (it->first == "redirect" && !it->second.empty()) {
				if (validPath(it->second))
					_redirect_page = it->second;
			}
			else if (it->first == "location" && !it->second.empty()) {
				string			locName = it->second;
				string			path;
				vector<string>	method;
				bool			listing = false;
				it++;
				while (it != c.end() && it->first != "listing") {
					if (it->first == "allowed_methods" && !it->second.empty()) {
						stringstream ss(it->second);
						string	meth;
						while (getline(ss, meth, ',')) {
							trim(&meth);
							if (validMethod(meth))
								method.push_back(meth);
						}
					}
					else if (it->first == "road" && !it->second.empty()) {
						if (validPath(it->second))
							path = it->second;
					}
					it++;
					if (it->first == "listing" && !it->second.empty()) {
						if (it->second == "true")
							listing = true;
					}
					if (it->first == "location") {
						it--;
						break ;
					}
				}
				if (!path.empty() && !method.empty())
					_location.insert(make_pair(locName, Location(locName, path, method, listing)));
			}
			else if (it->first == "cgi_extensions" && !it->second.empty()) {
				stringstream ss(it->second);
				string	ext;
				while (getline(ss, ext, ',')) {
					trim(&ext);
					if (ext == ".php" || ext == ".py")
						_cgiExtensions.push_back(ext);
				}
			}
			else if (it->first == "cgi.php" && !it->second.empty()) {
				if (validSysPath(it->second))
					_cgiHandlers[".php"] = it->second;
			}
			else if (it->first == "cgi.py" && !it->second.empty()) {
				if (validSysPath(it->second))
					_cgiHandlers[".py"] = it->second;
			}
			else if (it->first == "cgi_directory" && !it->second.empty()) {
				if (validPath(it->second))
					_cgiDirectory = it->second;
			}
		}
		it++;
	}
}

static void	emptyOrNot(const string& param, bool *corrupted) {
	if (param.empty()) {
		cout << REDD << "KO" << RST << endl;
		(*corrupted) = true;
	}
	else 
		cout << LIME << "OK" << RST << endl;
}

static bool	validLocation(const Location& loc) {
	if (loc.getPath().empty() || loc.getMethods().empty())
		return false;
	return true;
}

void	Server::validServ()	const {
	bool corrupted = false;

	cout << CYAN << "host" << RST << " : ";
	emptyOrNot(_host, &corrupted);
	cout << CYAN << "root"  << RST << " : ";
	emptyOrNot(_root, &corrupted);
	cout << CYAN << "server_name" << RST << " : ";
	if (_serverName.empty()) {
		cout << REDD << "KO" << RST << endl;
		corrupted = true;
	}
	else 
		cout << YLLW << _serverName << RST << " -> " << LIME << "OK" << RST << endl;
	cout << endl;
	cout << CYAN << "port" << RST << " -> ";
	if (_port.empty()) {
		cout << REDD << "KO" << RST << endl;
		corrupted = true;
	}
	else {
		for (vector<int>::const_iterator it = _port.begin(); it != _port.end(); it++) {
			cout << YLLW << *it << RST;
			if (it < _port.end() - 1)
				cout << " / ";
		}
		cout << LIME << " : OK" << RST << endl;
	}
	cout << endl;
	if (_location.size() < 2) {
		cout << CYAN << "location"  << RST << " : " << REDD << "KO" << RST << endl;
		corrupted = true;
	}
	for(map<string, Location>::const_iterator it = _location.begin(); it != _location.end(); it++) {
		cout << CYAN << "location " << RST;
		cout << " | " << PURP << "NAME" << RST << " : " << YLLW << it->second.getName() << RST << " |";
		if (!validLocation(it->second)) {
			cout << REDD << " : KO" << RST << endl;
			corrupted = true;
		}
		else {
			cout << PURP << " PATH" << RST << " : " << YLLW << it->second.getPath() << RST << " |";
			cout << PURP << " METHODS" << RST << " : ";
			vector<string> am = it->second.getMethods();
			for (vector<string>::iterator it = am.begin(); it != am.end(); it++) {
				cout << YLLW << *it << RST;
				if (it != am.end() - 1)
					cout << " - ";
				if (it == am.end() - 1)
					cout << " |";
			}
			cout << PURP << " LISTING" << RST << " : ";
			if (it->second.isListing())
				cout << YLLW << "true" << RST;
			else
				cout << YLLW << "false" << RST;
			cout << " ->" << LIME << " OK" << RST << endl;
		}
	}
	cout << endl;
	cout << CYAN << "default_page"  << RST << " : ";
	emptyOrNot(_default_page, &corrupted);
	cout << CYAN << "redirect"  << RST << " : ";
	emptyOrNot(_redirect_page, &corrupted);
	cout << endl;
	cout << CYAN << "max_body_size" << RST << " : ";
	if (_maxBodySize == -1) {
		cout << REDD << "KO" << RST << endl;
		corrupted = true;
	}
	else{
		cout << YLLW << _maxBodySize << RST << " octets : ";
		cout << LIME << "OK" << RST << endl;
	}
	cout << endl;
	cout << CYAN << "cgi_extensions" << RST << " : ";
	if (_cgiExtensions.size() != 2) {
		cout << REDD << "KO" << RST << endl;
		corrupted = true;
	}
	else
		cout << LIME << "OK" << RST << endl;
	if (_cgiHandlers.empty()) {
		cout << CYAN << "cgi.php" << RST << " : " << REDD << "KO" << RST << endl;
		cout << CYAN << "cgi.py" << RST << " : " << REDD << "KO" << RST << endl;
		corrupted = true;
	}
	else {
		bool php = false;
		bool py = false;
		for(map<string, string>::const_iterator it = _cgiHandlers.begin(); it != _cgiHandlers.end(); it++) {
			if (it->first == ".php") {
				cout << CYAN << "cgi.php" << RST << " : " << LIME << "OK" << RST << endl;
				php = true;
			}
			else if (it->first == ".py") {
				cout << CYAN << "cgi.py" << RST << " : " << LIME << "OK" << RST << endl;
				py = true;
			}
		}
		if (!php) {
			cout << CYAN << "cgi.php" << RST << " : " << REDD << "KO" << RST << endl;
			corrupted = true;
		}
		if (!py) {
			cout << CYAN << "cgi.py" << RST << " : " << REDD << "KO" << RST << endl;
			corrupted = true;
		}
	}
	cout << CYAN << "cgi_directory" << RST << " : " << RST;
	emptyOrNot(_cgiDirectory, &corrupted);
	cout << endl;
	if (corrupted)
		throw runtime_error("Configuration file corrupted.");
	cout << ">>> " << LIME << ITAL << "SERVER CONFIGURED SUCCESSFULLY" << RST << " <<<" << endl;
	cout << endl;
}

Server::Server(const vector<pair<string, string> >& config) {
	configServ(config);
	validServ();
}

Server::~Server() {}
