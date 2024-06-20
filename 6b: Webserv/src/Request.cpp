/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:35:37 by waziz             #+#    #+#             */
/*   Updated: 2024/06/20 09:55:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Request.hpp"

Request::Request(const Server& server, string buffer, int clientFd) : _server(server), _request(buffer), _clientFd(clientFd) {
	cout << LIME << "Request Received" << RST << ITAL << " for " << RST << BLUE << _server.getName() << RST << CYAN << "." << RST << endl;
	cout << PURP << "client_fd " << YLLW << _clientFd << RST << ITAL << " -> in request" << RST << endl;
	cout << _request << endl;
	cout << endl;
}

Request::~Request() {}