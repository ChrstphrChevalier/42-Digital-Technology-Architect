/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:01:55 by waziz             #+#    #+#             */
/*   Updated: 2024/05/28 00:03:22 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat Executor_One("Executor_One", 1);
		Bureaucrat Executor_Fifthy("Executor_Fifthy", 50);
		Bureaucrat Executor_Heighty("Executor_Heighty", 80);
		std::cout << std::endl;

		std::cout << Executor_One;
		std::cout << Executor_Fifthy;
		std::cout << Executor_Heighty;
		std::cout << std::endl;
		
		ShrubberyCreationForm Shrub_One("Shrub_One");
		ShrubberyCreationForm Shrub_Two("Shrub_Two");
		ShrubberyCreationForm Shrub_Three("Shrub_Three");
		std::cout << std::endl;

		std::cout << Shrub_One;
		std::cout << "| Shrub_One Target : " << Shrub_One.getTarget() << std::endl;
		std::cout << Shrub_Two;
		std::cout << "| Shrub_Two Target : " << Shrub_Two.getTarget() << std::endl;
		std::cout << Shrub_Three;
		std::cout << "| Shrub_Three Target : " << Shrub_Three.getTarget() << std::endl;
		std::cout << std::endl;

		RobotomyRequestForm Robot_One("Robot_One");
		RobotomyRequestForm Robot_Two("Robot_Two");
		RobotomyRequestForm Robot_Three("Robot_Three");
		std::cout << std::endl;

		std::cout << Robot_One;
		std::cout << "| Robot_One Target : " << Robot_One.getTarget() << std::endl;
		std::cout << Robot_Two;
		std::cout << "| Robot_Two Target : " << Robot_Two.getTarget() << std::endl;
		std::cout << Robot_Three;
		std::cout << "| Robot_Three Target : " << Robot_Three.getTarget() << std::endl;
		std::cout << std::endl;

		PresidentialPardonForm Presid_One("Presid_One");
		PresidentialPardonForm Presid_Two("Presid_Two");
		PresidentialPardonForm Presid_Three("Presid_Three");
		std::cout << std::endl;

		std::cout << Presid_One;
		std::cout << "| Presid_One Target : " << Presid_One.getTarget() << std::endl;
		std::cout << Presid_Two;
		std::cout << "| Presid_Two Target : " << Presid_Two.getTarget() << std::endl;
		std::cout << Presid_Three;
		std::cout << "| Presid_Three Target : " << Presid_Three.getTarget() << std::endl;
		std::cout << std::endl;

		std::cout << "!!!!!   EXECUTOR ONE   !!!!!!!!!" << std::endl;
		std::cout << std::endl;

		Executor_One.signForm(Shrub_One);
		Executor_One.signForm(Robot_One);
		Executor_One.signForm(Presid_One);
		std::cout << std::endl;
		Shrub_One.beSigned(Executor_One);
		Robot_One.beSigned(Executor_One);
		Presid_One.beSigned(Executor_One);
		std::cout << std::endl;

		Executor_One.executeForm(Shrub_One);
		Executor_One.executeForm(Robot_One);
		Executor_One.executeForm(Presid_One);
		std::cout << std::endl;
		Shrub_One.execute(Executor_One);
		Robot_One.execute(Executor_One);
		Presid_One.execute(Executor_One);
		std::cout << std::endl;

		std::cout << "!!!!!   EXECUTOR FIFTHY   !!!!!!!!!" << std::endl;
		std::cout << std::endl;

		Executor_Fifthy.signForm(Shrub_Two);
		Executor_Fifthy.signForm(Robot_Two);
		std::cout << std::endl;
		Shrub_Two.beSigned(Executor_Fifthy);
		Robot_Two.beSigned(Executor_Fifthy);
		std::cout << std::endl;

		Executor_Fifthy.executeForm(Shrub_Two);
		Shrub_Two.execute(Executor_Fifthy);
		std::cout << std::endl;

		// Executor_Fifthy.signForm(Presid_Two);
		// Executor_Fifthy.executeForm(Robot_Two);
		// Executor_Fifthy.executeForm(Presid_Two);
		// std::cout << std::endl;
		// Presid_Two.beSigned(Executor_Fifthy);
		// Robot_Two.execute(Executor_Fifthy);
		// Presid_Two.execute(Executor_Fifthy);
		// std::cout << std::endl;

		std::cout << "!!!!!   EXECUTOR HEIGHTY   !!!!!!!!!" << std::endl;
		std::cout << std::endl;

		Executor_Heighty.signForm(Shrub_Three);
		Shrub_Three.beSigned(Executor_Heighty);
		std::cout << std::endl;

		Executor_Heighty.executeForm(Shrub_Three);
		Shrub_Three.execute(Executor_Heighty);
		std::cout << std::endl;

		// Executor_Heighty.signForm(Robot_Three);
		// Executor_Heighty.signForm(Presid_Three);
		// std::cout << std::endl;
		// Executor_Heighty.executeForm(Robot_Three);
		// Executor_Heighty.executeForm(Presid_Three);
		// std::cout << std::endl;

		// Robot_Three.beSigned(Executor_Heighty);
		// Presid_Three.beSigned(Executor_Heighty);
		// std::cout << std::endl;
		// Robot_Three.execute(Executor_Heighty);
		// Presid_Three.execute(Executor_Heighty);
		// std::cout << std::endl;

	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const AForm::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}