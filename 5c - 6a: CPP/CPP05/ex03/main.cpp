/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:01:55 by waziz             #+#    #+#             */
/*   Updated: 2024/05/28 14:40:08 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Intern.hpp"

int main()
{
	Intern Slave;
	
	AForm* scf_1;
	AForm* scf_2;
	AForm* scf_3;

	AForm* rrf_1;
	AForm* rrf_2;
	AForm* rrf_3;

	AForm* ppf_1;
	AForm* ppf_2;
	AForm* ppf_3;

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
		
		scf_1 = Slave.makeForm("shrubbery creation", "Shrub_One");
		scf_2 = Slave.makeForm("shrubbery creation", "Shrub_Two");
		scf_3 = Slave.makeForm("shrubbery creation", "Shrub_Three");
		std::cout << std::endl;

		std::cout << *(scf_1);
		std::cout << "| Shrub_One Target : " << scf_1->getTarget() << std::endl;
		std::cout << *(scf_2);
		std::cout << "| Shrub_Two Target : " << scf_2->getTarget() << std::endl;
		std::cout << *(scf_3);
		std::cout << "| Shrub_Three Target : " << scf_3->getTarget() << std::endl;
		std::cout << std::endl;

		rrf_1 = Slave.makeForm("robotomy request", "Robot_One");
		rrf_2 = Slave.makeForm("robotomy request", "Robot_Two");
		rrf_3 = Slave.makeForm("robotomy request", "Robot_Three");
		std::cout << std::endl;

		std::cout << *(rrf_1);
		std::cout << "| Robot_One Target : " << rrf_1->getTarget() << std::endl;
		std::cout << *(rrf_2);
		std::cout << "| Robot_Two Target : " << rrf_2->getTarget() << std::endl;
		std::cout << *(rrf_3);
		std::cout << "| Robot_Three Target : " << rrf_3->getTarget() << std::endl;
		std::cout << std::endl;

		ppf_1 = Slave.makeForm("presidential pardon", "Presid_One");
		ppf_2 = Slave.makeForm("presidential pardon", "Presid_Two");
		ppf_3 = Slave.makeForm("presidential pardon", "Presid_Three");
		std::cout << std::endl;

		std::cout << *(ppf_1);
		std::cout << "| Presid_One Target : " << ppf_1->getTarget() << std::endl;
		std::cout << *(ppf_2);
		std::cout << "| Presid_Two Target : " << ppf_2->getTarget() << std::endl;
		std::cout << *(ppf_3);
		std::cout << "| Presid_Three Target : " << ppf_3->getTarget() << std::endl;
		std::cout << std::endl;

		std::cout << "!!!!!   EXECUTOR ONE   !!!!!!!!!" << std::endl;
		std::cout << std::endl;

		Executor_One.signForm(*scf_1);
		Executor_One.signForm(*rrf_1);
		Executor_One.signForm(*ppf_1);
		std::cout << std::endl;
		scf_1->beSigned(Executor_One);
		rrf_1->beSigned(Executor_One);
		ppf_1->beSigned(Executor_One);
		std::cout << std::endl;

		Executor_One.executeForm(*scf_1);
		Executor_One.executeForm(*rrf_1);
		Executor_One.executeForm(*ppf_1);
		std::cout << std::endl;
		scf_1->execute(Executor_One);
		rrf_1->execute(Executor_One);
		ppf_1->execute(Executor_One);
		std::cout << std::endl;

		std::cout << "!!!!!   EXECUTOR FIFTHY   !!!!!!!!!" << std::endl;
		std::cout << std::endl;

		Executor_Fifthy.signForm(*scf_2);
		Executor_Fifthy.signForm(*rrf_2);
		std::cout << std::endl;
		scf_2->beSigned(Executor_Fifthy);
		rrf_2->beSigned(Executor_Fifthy);
		std::cout << std::endl;

		Executor_Fifthy.executeForm(*scf_2);
		scf_2->execute(Executor_Fifthy);
		std::cout << std::endl;

		// Executor_Fifthy.signForm(*ppf_2);
		// Executor_Fifthy.executeForm(*rrf_2);
		// Executor_Fifthy.executeForm(*ppf_2);
		// std::cout << std::endl;
		// ppf_2->beSigned(Executor_Fifthy);
		// rrf_2->execute(Executor_Fifthy);
		// ppf_2->execute(Executor_Fifthy);
		// std::cout << std::endl;

		std::cout << "!!!!!   EXECUTOR HEIGHTY   !!!!!!!!!" << std::endl;
		std::cout << std::endl;

		Executor_Heighty.signForm(*scf_3);
		scf_3->beSigned(Executor_Heighty);
		std::cout << std::endl;

		Executor_Heighty.executeForm(*scf_3);
		scf_3->execute(Executor_Heighty);
		std::cout << std::endl;

		// Executor_Heighty.signForm(*rrf_3);
		// Executor_Heighty.signForm(*rrf_3);
		// std::cout << std::endl;
		// Executor_Heighty.executeForm(*rrf_3);
		// Executor_Heighty.executeForm(*ppf_3);
		// std::cout << std::endl;

		// rrf_3->beSigned(Executor_Heighty);
		// ppf_3->beSigned(Executor_Heighty);
		// std::cout << std::endl;
		// rrf_3->execute(Executor_Heighty);
		// ppf_3->execute(Executor_Heighty);
		// std::cout << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	delete scf_1;
	delete scf_2;
	delete scf_3;

	delete rrf_1;
	delete rrf_2;
	delete rrf_3;

	delete ppf_1;
	delete ppf_2;
	delete ppf_3;

	return (0);
}