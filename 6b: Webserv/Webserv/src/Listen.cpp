/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:02:31 by waziz             #+#    #+#             */
/*   Updated: 2024/06/19 12:55:09 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Listen.hpp"

static void	socketOptions(int socket_fd, bool *isValid) {
	int opt = 1;
	cout << PURP << "Options" << CYAN << " -> " << RST;
	// Configure l'option SO_REUSEADDR pour permettre la réutilisation de l'adresse réseau
	if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
		cout << ITAL << "SO_REUSEADDR" << RST << PURP << " : " << REDD << "failed" << GRY1 << " | " << RST;
		(*isValid) = false;
	}
	else
		cout << ITAL << "SO_REUSEADDR" << RST << PURP << " : " << LIME << "success" << GRY1 << " | " << RST;

	// Récupère les drapeaux actuels de la socket
	int flags = fcntl(socket_fd, F_GETFL, 0);
	if (flags == -1)
		(*isValid) = false;
	
	// Configure l'option O_NONBLOCK pour que la socket soit non bloquante
	if (fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
		cout << ITAL << "O_NONBLOCK" << RST << PURP << " : " << REDD << "failed" << RST << endl;;
		(*isValid) = false;
	}
	else
		cout << ITAL << "O_NONBLOCK" << RST << PURP << " : " << LIME << "succes" << RST << endl;;
}

static void	bindAndListen(int socket_fd, int port, bool *isValid) {
	struct sockaddr_in	addr;			// Déclare une structure sockaddr_in pour spécifier l'adresse et le port de la socket
	addr.sin_family = AF_INET;			// Spécifie que la famille d'adresses est IPv4
	addr.sin_addr.s_addr = INADDR_ANY;	// Assigne l'adresse IP à l'adresse spéciale INADDR_ANY pour accepter des connexions sur toutes les interfaces disponibles
	addr.sin_port = htons(port);		// Convertit le numéro de port de l'ordre des octets de l'hôte à l'ordre des octets du réseau (big-endian)
	bool	available = false;

	// Lie la socket à l'adresse et au port spécifiés
	if (bind(socket_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		cout << PURP << ITAL << "Availability" << RST << CYAN << " -> " << REDD << "KO" << RST << endl;
		(*isValid) = false;
	}
	else {
		cout << PURP << ITAL << "Availability" << RST << CYAN << " -> " << LIME << "OK" << RST << endl;
		available = true;
	}
	
	// Configure la socket pour écouter les connexions entrantes avec une file d'attente de 100 connexions
	if (listen(socket_fd, 100) < 0 || !available) {
		cout << PURP << ITAL << "Network" << RST << CYAN << " -> " << REDD << "KO" << RST << endl;
		(*isValid) = false;
	}
	else
		cout << PURP << ITAL << "Network" << RST << CYAN << " -> " << RST << addr.sin_port << GRY1 << " : " << LIME << "OK" << RST << endl;
}

void	Listen::createSockets(const vector<Server>& servers) {
	bool	validServer = false;
	for (vector<Server>::const_iterator its = servers.begin(); its != servers.end(); its++) {
		if (its != servers.begin())
			cout << endl;
		cout << GRY1 << "SERVER -> " << BLUE << its->getName() << RST << CYAN << " : " << RST << ITAL << "initilization..." << RST << endl;
		int	countPort = 0;
		const vector<int>& ports = its->getPorts();
		for (vector<int>::const_iterator itp = ports.begin(); itp != ports.end(); itp++) {
			bool	isValid = true;
			cout << CYAN << "port" << BLUE << " : " << RST << *itp << endl;
			int socket_fd = socket(AF_INET, SOCK_STREAM, 0); // Crée une nouvelle socket
			if (socket_fd < 0)
				throw runtime_error("Failed to create socket");
			socketOptions(socket_fd, &isValid);
			bindAndListen(socket_fd, *itp, &isValid);
			if (isValid) {
				cout << PURP << ITAL << "Socket_fd" << RST << CYAN << " -> " << YLLW << socket_fd << RST << endl;
				_sockets.push_back(socket_fd); // Ajoute la socket à la liste des sockets
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

void Listen::initKqueue() {
	cout << GRY1 << ITAL << "KQUEUE : " << RST << ITAL << "initialization..." << RST << endl;
	_kqueueFd = kqueue(); // Crée un nouvel objet kqueue et assigne son descripteur de fichier à _kqueueFd
	if (_kqueueFd == -1)
		throw runtime_error("Failed to create kqueue");
	cout << CYAN << "kqueue_fd" << RST << " : " << YLLW << _kqueueFd << RST << endl;
	
	struct kevent ev_set; // Déclare une structure kevent pour configurer les événements à surveiller
	for (vector<int>::const_iterator it = _sockets.begin(); it != _sockets.end(); it++) {
		// Initialise ev_set pour surveiller les événements de lecture (EVFILT_READ) sur la socket *it
		EV_SET(&ev_set, *it, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
		// |     |      |       |                |            |  |   |
		// |     |      |       |                |            |  |   +-----> Udata: NULL car pas de données utilisateur associées
		// |     |      |       |                |            |  +---------> fflags: Aucune option spéciale (0)
		// |     |      |       |                |            +------------> Data: Aucune donnée supplémentaire (0)
		// |     |      |       |                +-------------------------> Flags: EV_ADD | EV_ENABLE pour ajouter et activer l'événement
		// |     |      |       +------------------------------------------> Filter: EVFILT_READ pour surveiller les événements de lecture
		// |     |      +--------------------------------------------------> Ident: Descripteur de fichier de la socket (*it)
		// |     +---------------------------------------------------------> Kevent structure (ev_set) à initialiser
		// +---------------------------------------------------------------> Macro EV_SET pour initialiser une structure kevent

		// Ajoute l'événement à kqueue et vérifie s'il y a une erreur
		if (kevent(_kqueueFd, &ev_set, 1, NULL, 0, NULL) < 0) {
				//      |        |     |    |   |   |
				//      |        |     |    |   |   +----> Timeout: NULL signifie aucune attente, opère immédiatement
				//      |        |     |    |   +--------> Nombre maximum d'événements à retourner (0 ici, car nous n'attendons pas d'événements)
				//      |        |     |    +------------> Tableau pour stocker les événements retournés (NULL ici, car nous n'attendons pas d'événements)
				//      |        |     +-----------------> Nombre d'éléments dans changelist (1 ici, car nous ajoutons un événement)
				//      |        +-----------------------> Pointeur vers un tableau de kevent pour ajouter/modifier des événements (ici, &ev_set)
				//      +--------------------------------> Identifiant du kqueue à surveiller (_kqueueFd)

			cout << PURP << "socket_fd " << GRY2 << "-> " << YLLW << *it << CYAN << " | " << RST << "EVFILT_READ" << GRY1 << " : " << RST;
			throw runtime_error("Failed to add socket to kqueue");
		}
		cout << PURP << "socket_fd " << GRY2 << "-> " << YLLW << *it << CYAN << " | " << RST << "EVFILT_READ" << GRY1 << " : " << LIME << "connected" << RST <<  endl;
	}
}

void Listen::run(const vector<Server>& servers) {
    // Déclare un tableau de structures kevent pour stocker les événements
    struct kevent ev_list[1024];
    cout << CYAN << ITAL << "Running Webserv..." << RST << endl;
	cout << endl;

    while (true) {
        // Attend et récupère les événements sur kqueue, en les stockant dans ev_list
        int nev = kevent(_kqueueFd, NULL, 0, ev_list, 1024, NULL);
		//                   |      |     |      |     |     |
		//                   |      |     |      |     |     +-------> Timeout: NULL signifie attendre indéfiniment
		//                   |      |     |      |     +-------------> Nombre maximum d'événements à retourner (ici, 1024)
		//                   |      |     |      +-------------------> Tableau pour stocker les événements retournés
		//                   |      |     +--------------------------> Nombre d'éléments dans changelist (0 ici, car on n'ajoute ni ne modifie des événements)
		//                   |      +--------------------------------> Pointeur vers un tableau de kevent pour ajouter/modifier des événements (NULL ici, car on n'ajoute ni ne modifie des événements)
		//                   +---------------------------------------> Identifiant du kqueue à surveiller (_kqueueFd)
        if (nev < 0) {
            throw runtime_error("kevent error");
        }

        // Parcourt tous les événements récupérés
        for (int i = 0; i < nev; i++) {
            // Récupère l'identifiant du descripteur de fichier de l'événement
            int ev_fd = ev_list[i].ident;

            // Vérifie si l'événement est de type EVFILT_READ (lecture)
            if (ev_list[i].filter == EVFILT_READ) {
                // Vérifie si le descripteur de fichier appartient aux sockets serveur
                if (find(_sockets.begin(), _sockets.end(), ev_fd) != _sockets.end()) {
					// Déclare une structure sockaddr_in pour stocker les informations du client qui se connecte
                    struct sockaddr_in client_addr;
					// Déclare et initialise la variable client_len avec la taille de la structure client_addr
                    socklen_t client_len = sizeof(client_addr);
					// Accepte une nouvelle connexion entrante sur le descripteur de fichier ev_fd (évènement)
                    int client_fd = accept(ev_fd, (struct sockaddr*)&client_addr, &client_len);
					//    |                  |                        |                   |
					//    |                  |                        |                   +----> Pointeur vers la taille de la structure client_addr
					//    |                  |                        +------------------------> Structure contenant les informations du client accepté
					//    |                  +-------------------------------------------------> Descripteur de fichier sur lequel accepter la connexion (événement év_fd)
					//    +--------------------------------------------------------------------> Descripteur de fichier retourné pour la nouvelle connexion client (client_fd)

                    if (client_fd < 0) {
                        cout << REDD << "Error on accept" << RST << endl;
                        continue;
                    }

                    // Affiche un message indiquant qu'une nouvelle connexion a été acceptée
                    cout << LIME << "New connection accepted" << RST << " (" << PURP << "client_fd" << RST << " -> " << YLLW << client_fd << RST << ")" << endl;

                    // Configure un nouvel événement kevent pour surveiller les lectures sur le descripteur de fichier du client
                    struct kevent ev_set;
                    EV_SET(&ev_set, client_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
					// |       |         |           |             |            |  |    |
					// |       |         |           |             |            |  |    +----> Udata: NULL car pas de données utilisateur associées
					// |       |         |           |             |            |  +---------> fflags: Aucune option spéciale (0)
					// |       |         |           |             |            +------------> Data: Aucune donnée supplémentaire (0)
					// |       |         |           |             +-------------------------> Flags: EV_ADD | EV_ENABLE pour ajouter et activer l'événement
					// |       |         |           +---------------------------------------> Filter: EVFILT_READ pour surveiller les événements de lecture
					// |       |         +---------------------------------------------------> Ident: Descripteur de fichier pour lequel l'événement est configuré (client_fd)
					// |       +-------------------------------------------------------------> Kevent structure (ev_set) à initialiser
					// +---------------------------------------------------------------------> Macro EV_SET pour initialiser une structure kevent

                    // Ajoute le descripteur de fichier du client à kqueue et vérifie s'il y a une erreur
                    if (kevent(_kqueueFd, &ev_set, 1, NULL, 0, NULL) < 0) {
                        cout << REDD << "Failed to add client_fd to kqueue" << RST << endl;
                        close(client_fd);
                    }
                } else {
                }
            }
        }
    }
}
Listen::Listen(const vector<Server>& servers) {
	createSockets(servers);
	initKqueue();
	cout << endl;
	run(const vector<Server>& servers);
}

Listen::~Listen() {
	for (vector<int>::iterator it = _sockets.begin(); it != _sockets.end(); it++)
		close(*it);
	close(_kqueueFd);
}