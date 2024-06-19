/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:29:25 by waziz             #+#    #+#             */
/*   Updated: 2024/06/19 12:55:49 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#pragma once

# include "Location.hpp"

# include "librairies.hpp"

class Server {
	private:
		string					_host;
		string					_root;
		string					_serverName;

		vector<int>				_port;

		map<string, Location>	_location;

		string					_default_page;
		string					_redirect_page;

		long long int			_maxBodySize;
		
		vector<string>			_cgiExtensions;
		map<string, string>		_cgiHandlers;	
		string					_cgiDirectory;

		void					configServ(const vector<pair<string, string> >& config);
		void					validServ()	const;

	public:
		Server(const vector<pair<string, string> >& config, int iD);
		~Server();

		const vector<int>&	getPorts() const {
			return _port;
		}

		const string& 		getName() const {
			return _serverName;
		}
};

#endif