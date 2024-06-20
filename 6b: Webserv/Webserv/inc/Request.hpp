/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:26:10 by waziz             #+#    #+#             */
/*   Updated: 2024/06/20 11:21:35 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

#pragma once

# include "librairies.hpp"
# include "Server.hpp"

class Request {
	private :
		const Server&	_server;
		string			_request;
		int				_clientFd;

		string			_method;
		string			_asked_page;
		string			_httpVersion;
		string			_body;

	public:
		Request(const Server& server, string buffer, int clientFd);
		~Request();
};

#endif