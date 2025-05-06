/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:06:42 by waziz             #+#    #+#             */
/*   Updated: 2024/06/05 10:24:40 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		if (ac == 1)
			std::cout << "Error: could not open file." << std::endl;
		else
			std::cout << "Error argument: one by one only." << std::endl;
		return (0);
	}

	BitcoinExchange exchange = BitcoinExchange(av[1]);
	
	return (0);
}