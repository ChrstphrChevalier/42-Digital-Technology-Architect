/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:52:51 by waziz             #+#    #+#             */
/*   Updated: 2024/05/30 16:33:54 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "colors.hpp"
# include <iostream>
# include <exception>
# include <string>

template <typename T>
class Array {
	private:
		T* 				_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int size);
		Array(const Array& other);
		Array& operator=(const Array& affect);
		~Array();

		unsigned int size() const;
		T&	operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

# include "Array.tpp"

#endif