/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:12:42 by waziz             #+#    #+#             */
/*   Updated: 2024/05/30 14:30:38 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>


template <typename T>
void	swap(T& a, T& b) {
	T swap = a;

	a = b;
	b = swap;
}

template <typename T>
T		min(T& a, T& b) {
	return (a < b) ? a : b;
}

template <typename T>
T		max(T& a, T& b) {
	return (a > b) ? a : b;
}

#endif