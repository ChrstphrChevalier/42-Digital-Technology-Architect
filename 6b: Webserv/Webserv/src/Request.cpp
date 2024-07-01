/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:35:37 by waziz             #+#    #+#             */
/*   Updated: 2024/07/01 21:14:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

/*----------------------------------------------------------------------*/
/*            		  Parsing & Init Request			*/
//									//									//
/*			      - initRequest -				*/
/*----------------------------------------------------------------------*/

void	Request::initRequest(const string& buffer) {
	istringstream ss(buffer);
    string line;

    if (getline(ss, line)) {
        istringstream iss(line);
        iss >> _method >> _URi >> _httpVersion;

		_URi = _URi.substr(1);

        size_t pos = _URi.find('?');
        if (pos != string::npos) {
            _param = _URi.substr(pos + 1);
            _URi = _URi.substr(0, pos);
        }
    }
	
	while (getline(ss, line) && line != "\r") {
    	if (line.find("Host:") == 0)
            _host = line.substr(6);
        else if (line.find("Content-Type:") == 0)
            _contentType = line.substr(13);
        else if (line.find("Content-Length:") == 0)
            _contentLength = stoll(line.substr(16));
        else if (line.find("User-Agent:") == 0)
            _userAgent = line.substr(11);
	}

	if (ss.rdbuf()->in_avail() > 0)
        _body = string((istreambuf_iterator<char>(ss)), istreambuf_iterator<char>());
}

/*----------------------------------------------------------------------*/
/*            		   Request treatment				*/
//									//									//
/*		     	|	fileResp 	|			*/
/*			|     directoryResp 	|			*/
//									//									//
/*			      - treatment -				*/
/*----------------------------------------------------------------------*/

void	Request::fileResp(const Server& server) {
	if (!isMethod(server)) {
		_codeResp = 405;
		whichResp(server);
	} else if (isEmpty(_URi)) {
		_codeResp = 200;
		whichResp(server);
	} else {
		_isFile = true;
		_codeResp = 200;
		_respond = new Response(_codeResp, server.getName(), extFile(_URi), fileSize(_URi), _URi);
	}
}

void	Request::directoryResp(const Server& server) {
	if (!isListing(server)) {
		_codeResp = 403;
		whichResp(server);
	}
	else {
		_codeResp = 200;
		_respond = new Response(_codeResp, server.getName(), ".html", _URi);
	}
}

void Request::treatment(const string& method, const Server& server) {
	if (method == "GET") {
		if (_URi.empty()) {
			_URi = server.getRedirectPage();
			_codeResp = 200;
			if (!validPath(_URi) || isEmpty(_URi)) {
				_URi = "var/www/.index.html";
				_codeResp = 301;
			}
			_respond = new Response(_codeResp, server.getName(), extFile(_URi), fileSize(_URi), _URi);
			return ;
		}
		if (_URi == "WebCris" || _URi == "WebCed")
			_URi = server.getRoot();
		if (!validPath(_URi)) {
			_URi = server.getRoot() + "/" + _URi;
			if (!validPath(_URi))
				_codeResp = 404;
		}
		FDir whichOne = FileOrDir(_URi);
		switch(whichOne) {
			case F:
				fileResp(server);
				break;
			case D:
				directoryResp(server);
				break;
			case U:
				whichResp(server);
				break;
			default:
				break;
		}
	}
	else
		return ;
}

/*----------------------------------------------------------------------*/
/*            		  Constructor Request				*/
/*----------------------------------------------------------------------*/

Request::Request(const Server& server, const string& buffer, int clientFd) : _codeResp(0), _isFile(false), _respond(NULL) {
	
	cout << LIME << ITAL << "Request Received" << RST << GRY1 << " -> " << RST;
	cout << "(" << PURP << "client_fd" << RST << " : " << YLLW << clientFd << RST << ")";
	cout << GRY1 << ITAL << " for " << BLUE << server.getName() << RST << CYAN << "." << RST << endl;
	
	initRequest(buffer);
	treatment(_method, server);

	// cout << "RESPONSE" << endl;
	// if (_isFile)
	// 	cout << _respond->getHeader() << _respond->getFile() << endl;
	// else
	// 	cout << _respond->getResp() << endl;
}

/*----------------------------------------------------------------------*/
/*            		  Destructor Request				*/
/*----------------------------------------------------------------------*/

Request::~Request() {
	delete _respond;
	_respond = NULL;
}
