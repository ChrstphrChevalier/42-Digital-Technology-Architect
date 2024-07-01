/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:08:55 by waziz             #+#    #+#             */
/*   Updated: 2024/07/01 20:45:28 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "lib.hpp"
# include "Server.hpp"
# include "Html.hpp"

using namespace std;

class Response {
	private:
		Html				_html;
		
		string				_body;
		string				_header;

		string 				_file;
		string				_resp;


	public:
		Response(int codeResp, const string& name, const string& extension, size_t contentLength, const string& URi) {
			_header = _html.generateHeader(codeResp, name, extension, contentLength);
			_file = URi;
		}

		Response(int codeResp, const string& name, const string& extension) {
			_body = _html.generateErrPage(codeResp, name);
			_header = _html.generateHeader(codeResp, name, extension, _body.size());
			_resp = _header + _body;
		}

		Response(int codeResp, const string& name, const string& extension, const string& URi) {
			size_t pos = URi.find_last_of('/');
			string directory = URi.substr(pos + 1);
			_body = _html.generateListing(directory, URi);
			_header = _html.generateHeader(codeResp, name, extension, _body.size());
			_resp = _header + _body;
		}

		~Response() {};

		/* Getters */

		const string& 	getHeader() { return _header; }
		const string& 	getFile() { return _file; }
		const string&	getResp() { return _resp; }

};
