/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:00:53 by waziz             #+#    #+#             */
/*   Updated: 2024/06/01 01:22:17 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#pragma once

# include "colors.hpp"

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <climits>
# include <exception>

class Span {
	private:
		std::vector<int>	_numbers;
		uint				_N;

	public:
		Span();
		Span(const uint N);
		Span(const Span& other);
		Span& operator=(const Span& affect);
		~Span();

		uint				getN() const;
		std::vector<int>	getNbrs() const;
		
		void	addNumber(uint add);
		void	addNumbers(uint max);

		uint	shortestSpan() const;
		uint	longestSpan() const;
		

		class ElementAlreadyFilled : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif