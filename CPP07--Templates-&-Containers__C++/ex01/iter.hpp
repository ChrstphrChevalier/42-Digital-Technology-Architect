/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:35:32 by waziz             #+#    #+#             */
/*   Updated: 2024/05/30 21:38:49 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include "colors.hpp"
# include <iostream>
# include <string>

template <typename T>
void	iter(T *array, size_t length, void (*f)(const T&)) {
	for (size_t i = 0; i < length; i++)
		(*f)(array[i]);
}

#endif