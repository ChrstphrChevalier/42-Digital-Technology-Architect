/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:48:33 by waziz             #+#    #+#             */
/*   Updated: 2024/06/30 08:27:53 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "lib.hpp"

using namespace std;

class Location {
	private:
		string			_location;
		string			_path;
		vector<string>	_allowed_methods;
		bool			_autoIndex;

	public:
		Location(const string name, const string& path, const vector<string>& methods, bool autoindex)
        : _location(name), _path(path), _allowed_methods(methods), _autoIndex(autoindex) {}
		~Location() {
			_allowed_methods.clear();
		}

		const string&			getName() const {
			return _location;
		}
		const string&			getPath() const {
			return _path;
		}
		const vector<string>&	getMethods() const {
			return _allowed_methods;
		}
		bool					isAutoIndex() const {
			return _autoIndex;
		}
};
