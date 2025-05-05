/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:28:26 by waziz             #+#    #+#             */
/*   Updated: 2024/05/31 14:57:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#pragma once

# include "colors.hpp"

# include <iostream>
# include <string>

# include <vector>
# include <list>
# include <deque>
# include <set>
# include <unordered_set>

template <typename T>
typename T::const_iterator	easyfind(const T& container, int occurence) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), occurence);
	if (it == container.end())
		throw std::runtime_error(GRY2 "Occurence " RED1 "not found" GRY2 " in container" RST);
	std::cout << LIME "- Element " GOLD << "(" << occurence << ") " << LIME "found ! -" << RST << std::endl;
	return it;
}

#endif