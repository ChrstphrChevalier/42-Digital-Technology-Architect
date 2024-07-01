/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:26:10 by waziz             #+#    #+#             */
/*   Updated: 2024/07/01 20:49:44 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "lib.hpp"
# include "Server.hpp"
# include "Response.hpp"
# include "Html.hpp"

using namespace std;

enum FDir {
	F,
	D,
	U
};

class Request {
	private :
		/* Request */
		string					_method;
		string					_URi;
		string					_param;
		string					_httpVersion;

		string					_host;
		string					_contentType;
		unsigned long long int	_contentLength;
		string 					_userAgent;

		string					_body;

		/* Response */
		int						_codeResp;
		bool 					_isFile;

		string					_errorPath;

		void	initRequest(const string& buffer);
		void	fileResp(const Server& server);
		void	directoryResp(const Server& server);
		void 	treatment(const string& method, const Server& server);

		/* Methods */

		bool 			isMethod(const Server& server) {
			string directory;
			size_t pos = _URi.find_last_of('/');
			if (pos != string::npos) {
				directory = _URi.substr(0, pos);

				pos = directory.find_last_of('/');
				if (pos != string::npos)
					directory = directory.substr(pos + 1);
				const map<string, Location>& locations = server.getLocation();
				map<string, Location>::const_iterator it = locations.find(directory);
				if (it != locations.end()) {
					const vector<string>& methods = it->second.getMethods();
					if (find(methods.begin(), methods.end(), _method) != methods.end())
						return true;
				}
			}
			return false;
		}

		bool 			validPath(const string& path) {
			struct stat info;
			return stat(path.c_str(), &info) == 0;
		}

		FDir FileOrDir(const string& path) {
			struct stat info;
			if (stat(path.c_str(), &info) == 0) {
				if (info.st_mode & S_IFREG)
					return F;
				else if (info.st_mode & S_IFDIR)
					return D;
			}
			return U;
		}

		bool 			isEmpty(const string& URi) {
			ifstream file(URi, ios::ate);
			return file.tellg() == 0;
		}

		bool			isError(const map<string, Location>& location, int codeResp) {
			for (map<string, Location>::const_iterator it = location.begin(); it != location.end(); it++)
				if (it->first == "error") {
					_errorPath = it->second.getPath();
			
					ostringstream oss;
					oss << codeResp;
					_errorPath = _errorPath + oss.str() + ".html";
					if (validPath(_errorPath) && !isEmpty(_errorPath))
						return true;
			}
			return false;
		}

		void			whichResp(const Server& server) {
			if (isError(server.getLocation(), _codeResp)) {
				_isFile = true;
				_URi = _errorPath;
				_respond = new Response(_codeResp, server.getName(), extFile(_URi), fileSize(_URi), _URi);
			} else {
				_URi.clear();
				_respond = new Response(_codeResp, server.getName(), ".html");
			}
		}

		size_t 			fileSize(const string& URi) {
			ifstream file(URi, ios::ate | ios::binary);
			if (!file.is_open()) {
				std::cerr << "Could not open the file: " << URi << std::endl;
				return 0;
			}
			return file.tellg();
		}

		const string	extFile(const string& URi) {
			size_t pos = URi.find_last_of('.');
			if (pos != string::npos)
				return URi.substr(pos);
			return "";
		}

		bool 			isListing(const Server& server) {
			string directory;
			size_t pos = _URi.find_last_of('/');
			if (pos != string::npos) {
				directory = _URi.substr(pos + 1);

				const map<string, Location>& locations = server.getLocation();
				map<string, Location>::const_iterator it = locations.find(directory);
				if (it != locations.end())
					if (it->second.isAutoIndex())
						return true;
			}
			return false;
		}

	public:
		Request(const Server& server, const string& buffer, int clientFd);
		~Request();

		Response				*_respond;

		/* Getters */
		bool			isFile() { return _isFile; }
};
