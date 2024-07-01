/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:50:14 by waziz             #+#    #+#             */
/*   Updated: 2024/06/30 08:41:36 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "lib.hpp"
# include "Server.hpp"
# include "Request.hpp"

using namespace std;

class Listen {
	private:
		vector<int>					_sockets;
		map<int, const Server&>		_whichServ;
		Request						*_req;
		int							_kqueueFd;

		void	createSockets(const vector<Server>& servers);
		void	initKqueue();

		static void 	signal(int sig);
		void 			setup_signal();

		int		addClient(int *ev_fd, int *mem_fd);
		void	recept_request(int ev_fd, int mem_fd, map<int, string>& req_buffer, \
						map<int, ssize_t>& req_length, map<int, pair<istringstream*, ifstream*> >& rs);
		void	send_response(int ev_fd, map<int, pair<istringstream*, ifstream*> >& rs);
		void	run();

	public:
		Listen(const vector<Server>& servers);
		~Listen();
};
