/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:26:10 by waziz             #+#    #+#             */
/*   Updated: 2024/06/19 12:56:35 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP

# include "librairies.hpp"
# include "Server.hpp"

class Request {
	private :
		const Server&	_server;
		string			_request;
		string			_method;
		string			_asked_page;
		string			_httpVersion;
		string			_body;

	public:
		Request(const Server& server, string totalRequest);
		~Request();
};

#endif