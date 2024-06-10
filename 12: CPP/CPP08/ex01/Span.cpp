/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:03:33 by waziz             #+#    #+#             */
/*   Updated: 2024/06/01 09:51:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span() {
	std::cout << "Span :" << YLLW << " Default constructor called" << RST << std::endl;
}

Span::Span(uint N) : _N(N) {
	std::cout << "Span : " << YLLW << "Custom constructor called with size of Container -> " << _N << RST << std::endl;
}

Span::Span(const Span& other) : _N(other.getN()) {
	std::cout << "Span : " << YLLW << "Copy constructor called" << RST << std::endl;
}

Span& Span::operator=(const Span& affect) {
	if (this != &affect)
		_N = affect.getN();
	return (*this);
}

Span::~Span() {
	std::cout << "Span : " << YLLW << "Destructor called" << RST << std::endl;
}

uint	Span::getN() const {
	return _N;
}

std::vector<int>	Span::getNbrs() const {
	return _numbers;
}

uint	Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error(REDD "Not enough numbers to find a span." RST);
	
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	uint shortest = UINT_MAX;
	uint current;
    for (size_t i = 0; i < tmp.size() - 1; i++) {
		current = tmp[i + 1] - tmp[i];
		if (current < shortest)
			shortest = current;
	}
	return shortest;
}

uint	Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error(REDD "Not enough numbers to find a span." RST);
	
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	int last = tmp.size() - 1;
	return tmp[last] - tmp[0];
}

const char*	Span::ElementAlreadyFilled::what() const throw() {
	static std::string errMsg = REDD "The container is full, buy yourself a house" RST;
	return errMsg.c_str();
}

void	Span::addNumber(uint add) {
	if (_numbers.size() == _N)
		throw ElementAlreadyFilled();
	_numbers.push_back(add);
}

void	Span::addNumbers(uint max) {
	if (max > _N)
		throw std::logic_error(REDD "Too many numbers, in relation to the capacity of the container" RST);
	for (uint i = 0; i < max; i++)
		_numbers.push_back(i * 19);
}