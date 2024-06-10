/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:49:00 by waziz             #+#    #+#             */
/*   Updated: 2024/06/05 15:38:57 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#pragma once

# include "colors.hpp"

# include <iostream>
# include <exception>
# include <string>
# include <stack>

class RPN {
	private:
		RPN();

		std::stack<int> _rpn;
		int				_result;
		bool			_start;
		bool			_valid;

		void	switchCase(char c, int topElement);
		void 	calculator(char c);
		void	notation(std::string polish);

	public:
		RPN(std::string polish);
		RPN(const RPN& other);
		RPN& operator=(const RPN& affect);
		~RPN();

		void	getRPN()	const;

};

#endif