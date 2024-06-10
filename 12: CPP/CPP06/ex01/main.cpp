/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:31:54 by waziz             #+#    #+#             */
/*   Updated: 2024/05/29 20:54:06 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1) {
		std::cout << "Usage : ./exec" << std::endl;
		return (0);
	}

	Data ptr;
	uintptr_t reinterpreted;

	ptr.str = "Mada Fucka";
	reinterpreted = Serializer::serialize(&ptr);

	std::cout << "(Data)Address : " << &ptr << std::endl;
	std::cout << "(Data)ptr value = " << ptr.str << std::endl;
	std::cout << std::endl;

	std::cout << "(Data)Reinterpreted ptr value : " << reinterpreted << std::endl;
	std::cout << std::endl;

	Data *deserialize;
	deserialize = Serializer::deserialize(reinterpreted);

	std::cout << "Deserialize address : " << deserialize << std::endl;
	std::cout << "str value : " << deserialize->str << std::endl;

	return (0);
}