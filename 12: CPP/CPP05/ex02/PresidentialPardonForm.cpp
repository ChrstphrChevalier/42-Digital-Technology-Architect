/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:10:34 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 23:39:25 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("AForm -> PresidentialPardonForm", 25, 25) {
	std::cout << "PresidentialPardonForm : Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("AForm -> PresidentialPardonForm", 25, 25), _target(target) {
	std::cout << "PresidentialPardonForm : Target constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
	setSigned(other.getSigned());
	std::cout << "PresidentialPardonForm : Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& affect) {
	if (this != &affect)
		setSigned(affect.getSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm : Destructor called" << std::endl;
}

const std::string&	PresidentialPardonForm::getTarget()	const {
	return _target;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor)	const {
	if (!getSigned())
		throw GradeTooLowException(executor.getName(), "sign");
	else if (executor.getGrade() > getG_toExec())
		throw GradeTooLowException(executor.getName(), "exec");
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}