/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:29:25 by waziz             #+#    #+#             */
/*   Updated: 2024/06/30 08:27:03 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "lib.hpp"
# include "Location.hpp"

using namespace std;

class Server {
	private:
		string					_host;
		string					_root;
		string					_serverName;

		vector<int>				_port;

		map<string, Location>	_location;

		string					_default_directory;
		string					_default_page;
		string					_redirect_page;

		long long int			_maxBodySize;
		
		vector<string>			_cgiExtensions;
		map<string, string>		_cgiHandlers;	
		string					_cgiDirectory;

		void					configServ(const vector<pair<string, string> >& config);
		void					validServ()	const;

	public:
		Server(const vector<pair<string, string> >& config);
		~Server();

		/* Getters */
		const string& 					getHost() const { return _host; }
		const string& 					getRoot() const { return _root; }
		const string& 					getName() const { return _serverName; }
		const vector<int>&				getPorts() const { return _port; }
		const map<string, Location>&	getLocation() const { return _location; }
		const string& 					getDefaultDirectory() const { return _default_directory; }
		const string& 					getDefaultPage() const { return _default_page; }
		const string& 					getRedirectPage() const { return _redirect_page; }
		long long int					getMaxBodySize() const { return _maxBodySize; }
		const vector<string>& 			getCgiExtensions() const { return _cgiExtensions; }
		const map<string, string>& 		getCgiHandlers() const { return _cgiHandlers; }
		const string& 					getCgiDirectory() const { return _cgiDirectory; }
};
