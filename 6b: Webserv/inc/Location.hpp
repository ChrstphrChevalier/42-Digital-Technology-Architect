/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:48:33 by waziz             #+#    #+#             */
/*   Updated: 2024/06/15 00:57:09 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LOCATION_HPP
# define LOCATION_HPP

#pragma once

# include "librairies.hpp"

class Location {
	private:
		string			_location;
		string			_path;
		vector<string>	_allowed_methods;
		bool			_listing;

	public:
		Location(const string name, const string& path, const vector<string>& methods, bool listing)
        : _location(name), _path(path), _allowed_methods(methods), _listing(listing) {}
		~Location() {}

		const string&			getName() const {
			return _location;
		}
		const string&			getPath() const {
			return _path;
		}
		const vector<string>&	getMethods() const {
			return _allowed_methods;
		}
		bool					isListing() const {
			return _listing;
		}
};

#endif