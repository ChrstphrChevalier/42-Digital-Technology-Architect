/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:10:42 by waziz             #+#    #+#             */
/*   Updated: 2024/05/29 23:46:22 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

static Base*	generate() {
	char c = "ABC"[(rand() % 3)];

	std::cout << "Type : " << c << " created" << std::endl;
	switch(c) {
		case 'A':
			return new A;
		case 'B':
			return new B;
		case 'C':
			return new C;
	}
	return (NULL);
}

static void	identify(Base *p) {
	bool thisOne = false;
	std::cout << "The * identified is : ";

    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
	
	Base*	ptr[3] = { a, b, c };
	char	bases[3] = { 'A', 'B', 'C' };
	for (int i = 0; i < 3; i++) {
		if (ptr[i]) {
			thisOne = true;
			std::cout << bases[i] << std::endl;
			break ;
		}
	}
	if (!thisOne)
		std::cout << "Invalid type" << std::endl;
}

static void identify(Base& p) {
	std::cout << "The reference identified is : ";
	
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::bad_cast) {
		try {
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::bad_cast) {
			try {
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(const std::bad_cast) {
				std::cout << "Invalid type" << std::endl;
			}
			
		}
		
	}
	
}

// main in black

int main(int ac, char **av)
{
	(void)av;
	srand(time(NULL));
	if (ac != 1) {
		std::cout << "Usage : ./exec" << std::endl;
		return (0);
	}

	Base *random;
	for (int engine = 0; engine < 9; engine++) {
		random = generate();
		identify(random);
		identify(*random);
		std::cout << std::endl;
		delete random;
	}
	return (0);
}