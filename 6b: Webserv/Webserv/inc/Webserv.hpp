/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:27:24 by waziz             #+#    #+#             */
/*   Updated: 2024/06/18 15:05:46 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

#pragma once

# include "Server.hpp"
# include "Listen.hpp"

# include "librairies.hpp"

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

#endif