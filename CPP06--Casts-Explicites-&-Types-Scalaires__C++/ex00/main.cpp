/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:14:28 by waziz             #+#    #+#             */
/*   Updated: 2024/05/29 21:16:58 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	for(int i = 1; i < ac; i++) {
		ScalarConverter::convert(av[i]);
		std::cout << std::endl;
	}
	return (0);
}
