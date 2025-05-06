/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:01:55 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 15:09:17 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

int main()
{
	Bureaucrat Default;
	std::cout << Default;
	std::cout << std::endl;

	Form byDefault;
	std::cout << byDefault;
	std::cout << std::endl;

	try 
	{
		Bureaucrat Boss("Boss", 1);
		std::cout << Boss;
		std::cout << std::endl;

		Form rankS("Rank S", 20, 20);
		std::cout << rankS;
		std::cout << std::endl;

		Default.signForm(byDefault);
		std::cout << std::endl;
		byDefault.beSigned(Default);
		std::cout << std::endl;

		Boss.signForm(rankS);
		std::cout << std::endl;
		rankS.beSigned(Boss);
		std::cout << std::endl;

		Default.signForm(rankS);
		std::cout << std::endl;
		rankS.beSigned(Default);
		std::cout << std::endl;

		std::cout << rankS;
		std::cout << std::endl;

		std::cout << byDefault;
		std::cout << std::endl;
		
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Form::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}