/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:47:43 by waziz             #+#    #+#             */
/*   Updated: 2024/06/03 15:56:45 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#pragma once

# include "colors.hpp"

# include <iostream>
# include <stack>
# include <deque>

template < typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
	public:
		MutantStack() {};
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& affect);
		~MutantStack() {};

		typedef typename C::iterator it;

		it begin() { return this->c.begin(); }
		it end() { return this->c.end(); }
};

#endif