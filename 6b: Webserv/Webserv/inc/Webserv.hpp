/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:27:24 by waziz             #+#    #+#             */
/*   Updated: 2024/06/30 08:26:57 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "lib.hpp"
# include "Server.hpp"
# include "Listen.hpp"

using namespace std;

class Webserv {
	private:
		vector<vector<pair<string, string> > >	_settings;
		vector<Server>							_servers;

		Listen									*_listen;

		void	parseConfig(const string& config);
		void	addServ();
		
	public:
		Webserv(const string& config);
		~Webserv();

};
