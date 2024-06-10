/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:59:31 by waziz             #+#    #+#             */
/*   Updated: 2024/05/30 21:51:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& affect) {
	if (this != &affect)
	{
		delete [] _array;
		_array = new T[affect._size];
		_size = affect._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = affect._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	static std::string ErrMsg = " OutOfBoundsException : bad access";
	return ErrMsg.c_str();
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

#endif