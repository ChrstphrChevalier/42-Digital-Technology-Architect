/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:53:08 by waziz             #+#    #+#             */
/*   Updated: 2024/06/03 10:51:44 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack& other) : std::stack<T,C>(other) {
	std::cout << "MutantStack : Copy constructor called" << std::endl;
	this->c = other.c;
}

template <typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack& affect) {
	if (this != &affect) {
		std::stack<T, C>::operator=(affect);
		this->c = affect.c;
	}
	return (*this);
}