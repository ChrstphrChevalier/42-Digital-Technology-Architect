/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:03:41 by waziz             #+#    #+#             */
/*   Updated: 2024/06/01 09:09:01 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

static void	that_works() {
	for (int i = 2; i < 15; i++) {
		try {
			Span tw = Span(i);

			tw.addNumbers(i);

			std::cout << LIME << "CONTAINER -> " << i << " : VALUE ADDED" << RST << std::endl;
			for (size_t i = 0; i < tw.getN(); i++) {
				if (i < tw.getN() - 1)
					std::cout << GRY2 << tw.getNbrs()[i] << " | " << RST;
				else
					std::cout << GRY2 << tw.getNbrs()[i] << RST << std::endl;
			}
			std::cout << std::endl;

			std::cout << PURP << "Shortest" << RST;
			std::cout << " -> " << CYAN << tw.shortestSpan() << RST << std::endl;
			std::cout << PURP << "Longest" << RST;
			std::cout << " -> " << CYAN << tw.longestSpan() << RST << std::endl;
		} catch (std::exception& e) {
			std::cout << PURP << "Exception" << RST << " -> ";
			std::cout << e.what() << std::endl; }
		if (i < 14)
			std::cout << std::endl;
	}
}

static void	catch_exception() {
	std::cout << LIME << "WE ADD AN EXTRA NUMBER" << RST << std::endl;

	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch (std::exception& e) {
		std::cout << PURP << "Exception" << RST << " -> ";
		std::cout << e.what() << std::endl; }
	std::cout << std::endl;

	std::cout << LIME << "ONLY ONE NUMBER HAS BEEN ADDED" << RST << std::endl;

	try {
		Span sp = Span(5);

		sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch (std::exception& e) {
		std::cout << PURP << "Exception" << RST << " -> ";
		std::cout << e.what() << std::endl; }
	std::cout << std::endl;

	std::cout << LIME << "MAX GREATER THAN SIZE INITIALIZED VIA ITERATOR" << RST << std::endl;

	try {
		Span sp = Span(10);

		sp.addNumbers(42);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch (std::exception& e) {
		std::cout << PURP << "Exception" << RST << " -> ";
		std::cout << e.what() << std::endl; }
}

static void schoolTest() {
	Span st = Span(5);

	st.addNumber(6);
	st.addNumber(3);
	st.addNumber(17);
	st.addNumber(9);
	st.addNumber(11);

	std::cout << LIME << "VALUE ADDED" << RST << std::endl;
	for (size_t i = 0; i < st.getN(); i++) {
		if (i < st.getN() - 1)
			std::cout << GRY2 << st.getNbrs()[i] << " | " << RST;
		else
			std::cout << GRY2 << st.getNbrs()[i] << RST << std::endl;
	}
	std::cout << std::endl;

	std::cout << PURP << "Shortest" << RST;
	std::cout << " -> " << CYAN << st.shortestSpan() << RST << std::endl;
	std::cout << PURP << "Longest" << RST;
	std::cout << " -> " << CYAN << st.longestSpan() << RST << std::endl;
}

int main () {

	std::cout << std::endl;
	std::cout << PURP << "SUBJECT TEST" << BLUE << " {" << RST << std::endl;
	schoolTest();
	std::cout << BLUE << "}" << RST << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << PURP << "CATCH TEST" << BLUE << " {" << RST << std::endl;
	catch_exception();
	std::cout << BLUE << "}" << RST << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << PURP << "TEST THAT WORKS" << BLUE << " {" << RST << std::endl;
	std::cout << ORNG << "We create containers of two to fifteen numbers. They all start from index i = 0 to their limit and then each index = i * 19;" << RST << std::endl;
	std::cout << std::endl;
	that_works();
	std::cout << BLUE << "}" << RST << std::endl;
	std::cout << std::endl;

	return 0;
}