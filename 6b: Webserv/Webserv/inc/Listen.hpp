/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:50:14 by waziz             #+#    #+#             */
/*   Updated: 2024/06/20 12:02:51 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTEN_HPP
# define LISTEN_HPP

#pragma once

# include "librairies.hpp"

# include "Server.hpp"
# include "Request.hpp"

class Listen {
	private:
		vector<int>					_sockets;
		map<int, const Server&>		_whichServ;
		vector<Request>				_requests;
		int							_kqueueFd;

		void	createSockets(const vector<Server>& servers);
		void	initKqueue();
		void	run();

	public:
		Listen(const vector<Server>& servers);
		~Listen();
};

#endif