/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:01:55 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 15:06:57 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Default;
	std::cout << std::endl;
	std::cout << Default;
	std::cout << std::endl;

	try 
	{
		Bureaucrat Ambitious("Ambitious", 50);
		std::cout << Ambitious;
		
		Ambitious.setGrade(1);
		std::cout << Ambitious;

		Ambitious.increment();
		std::cout << Ambitious;

		Ambitious.decrement();
		std::cout << Ambitious;

		Ambitious = Default;
		std::cout << Ambitious;
		Ambitious.decrement();
		std::cout << Ambitious;
		std::cout << std::endl;

		Bureaucrat Special = Ambitious;
		Special.setGrade(1);
		std::cout << Special;
		std::cout << std::endl;

		Default.setGrade(1);
		Ambitious.setGrade(150);
		Special.setGrade(0);

		std::cout << "DEFAULT CLASS" << std::endl;
		std::cout << Default;
		std::cout << std::endl;
		std::cout << "AMBITIOUS CLASS" << std::endl;
		std::cout << Ambitious;
		std::cout << std::endl;
		std::cout << "SPECIAL CLASS" << std::endl;
		std::cout << Special;
		std::cout << std::endl;
		
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}