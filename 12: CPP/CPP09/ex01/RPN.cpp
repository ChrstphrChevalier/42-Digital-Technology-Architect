/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:11:19 by waziz             #+#    #+#             */
/*   Updated: 2024/06/05 16:04:53 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN() {
	std::cout << YLLW << "RPN :" << RST << " Default constructor called" << std::endl;
}

RPN::RPN(std::string polish) {
	std::cout << YLLW << "RPN :" << RST << " Custom constructor called" << std::endl;
	try {
		notation(polish);
	} catch (std::exception& e) {
		std::cout << REDD << e.what() << RST << std::endl;
	}
}

RPN::RPN(const RPN& other) : _result(other._result), _valid(other._valid) {
	std::cout << YLLW << "RPN :" << RST << " Copy constructor called" << std::endl;
	if (_valid)
		std::cout << MAGN << _result << RST << std::endl;
	else
		std::cout << REDD << "RPN : Calculation impossible" << RST << std::endl;
}

RPN& RPN::operator=(const RPN& affect) {
	if (this != &affect) {
		_result = affect._result;
		_valid = affect._valid;
	}
	return (*this);
}

RPN::~RPN() {
	std::cout << YLLW << "RPN :" << RST << " Destructor called" << std::endl;
}

void	RPN::getRPN()	const {
	if (_valid)
		std::cout << MAGN << _result << RST << std::endl;
	else
		std::cout << REDD << "RPN : Calculation impossible" << RST << std::endl;
}

void	RPN::switchCase(char c, int topElement) {
	switch (c) {
	case '+':
		_result += topElement;
		break;
	case '-':
		_result -= topElement;
		break;
	case '*':
		_result *= topElement;
		break;
	case '/':
		if (topElement == 0)
			throw std::logic_error("RPN : Division by zero impossible");
		_result /= topElement;
		break;
	default :
		throw std::logic_error("Calculation Impossible");
	}
}

void 	RPN::calculator(char c) {
	if (_start) {
		_result = _rpn.top(); _rpn.pop();
		_start = false;
	}
	if (_rpn.empty())
		throw std::logic_error("RPN : Calculation impossible");
	int topElement = _rpn.top(); _rpn.pop();
	if (_rpn.size() == 1) {
		int tmp = _rpn.top(); _rpn.pop();
		switch (c) {
			case '+':
				tmp += topElement;
				_rpn.push(tmp);
				return;
			case '-':
				tmp -= topElement;
				_rpn.push(tmp);
				return;
			case '*':
				tmp *= topElement;
				_rpn.push(tmp);
				return;
			case '/':
				if (topElement == 0)
					throw std::logic_error("RPN : Division by zero impossible");
				tmp /= topElement;
				_rpn.push(tmp);
				return;
			default :
				throw std::logic_error("Calculation Impossible");
		}
	}
	switchCase(c, topElement);
}

void	RPN::notation(std::string polish) {
	_start = true;
	_valid = false;
	for (size_t i = 0; i < polish.length(); i++) {
		if (isdigit(polish[i]))
			_rpn.push(std::stoi(std::string(1, polish[i])));
		else if (polish[i] == '+' || polish[i] == '-' || polish[i] == '*' || polish[i] == '/')
			calculator(polish[i]);
		else if (polish[i] == 32)
			continue;
		else
			throw std::logic_error("RPN : Invalid character for Reverse Polish Notation");
	}
	if (!_rpn.empty())
		throw std::logic_error("Calculation impossible");
	_valid = true;
	std::cout << CYAN << _result << RST << std::endl;
}