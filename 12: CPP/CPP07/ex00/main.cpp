/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:14:34 by waziz             #+#    #+#             */
/*   Updated: 2024/05/30 14:29:34 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;

	std::cout << "BEFORE swap : ";
	std::cout << "a -> " << a << ", b -> " << b << std::endl;
	std::cout << std::endl;

	std::cout << "AFTER swap : ";
	::swap( a, b );
	std::cout << "a -> " << a << ", b -> " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "BEFORE swap : ";
	std::cout << "c -> " << c << ", d -> " << d << std::endl;
	std::cout << std::endl;
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
}