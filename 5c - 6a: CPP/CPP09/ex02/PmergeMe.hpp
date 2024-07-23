/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:14:55 by waziz             #+#    #+#             */
/*   Updated: 2024/07/23 22:24:31 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#pragma once

# include "colors.hpp"

# include <iostream>
# include <cstring>

# include <list>
# include <deque>
# include <vector>

# include <algorithm>
# include <iterator>

# include <ctime>
# include <cstdlib>

class PmergeMe {
	public:
		PmergeMe(int ac, char **av);

	private:

		template <typename Container, typename Iterator>
		void insertionSort(Container& container, Iterator start, Iterator end);

		template <typename Container, typename Iterator>
		void merge(Container& container, Iterator left, Iterator mid, Iterator right);

		template <typename Container, typename Iterator>
		void _FordJohnsonSort(Container& container, Iterator left, Iterator right);

		template <typename Container>
    	void FordJohnson(Container& container);

		template <typename T>
		void	display(const T& container, int option);

};

#endif