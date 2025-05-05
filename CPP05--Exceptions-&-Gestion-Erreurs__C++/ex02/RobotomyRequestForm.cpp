/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:00:29 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 23:39:10 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("AForm -> RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm : Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("AForm -> RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm : Target constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
	setSigned(other.getSigned());
	std::cout << "RobotomyRequestForm : Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& affect) {
	if (this != &affect)
		setSigned(affect.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm : Destructor called" << std::endl;
}

const std::string&	RobotomyRequestForm::getTarget()	const {
	return _target;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor)	const {
	if (!getSigned())
		throw GradeTooLowException(executor.getName(), "sign");
	else if (executor.getGrade() > getG_toExec())
		throw GradeTooLowException(executor.getName(), "exec");
	else
	{
        static int  round;
        if ( round % 2 == 0 )
            std::cout << "BBBZZZZZZZZTTT! " << _target << " has been robotomized!" << std::endl;
        else
            std::cout << " bb zzz tt .. Robotomy failed! " << _target << " is still alive." << std::endl;
        round++;
	}
}