/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:41:40 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 14:56:36 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat Default"), _grade(150) {
    std::cout << "Bureaucrat : Default constructor called." << std::endl;
	std::cout << "Bureaucrat starts at lowest grade." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int G) : _name(name) {
    std::cout << _name << " : constructor called." << std::endl;
	setGrade(G);
}

Bureaucrat::~Bureaucrat() {
    std::cout << _name << " : Destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << _name << " : copy constructor called." << std::endl;
}

Bureaucrat&    Bureaucrat::operator=(const Bureaucrat& affect) {
    if (this != &affect)
        _grade = affect._grade;
    return (*this);
}

void    Bureaucrat::setGrade(int G) {
    if (G < 1)
        throw GradeTooLowException(_name);
    else if (G > 150)
        throw GradeTooHighException(_name);
    else
        _grade = G;		
}

std::string Bureaucrat::getName() const {
    	return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void	Bureaucrat::signForm(const AForm& f) const {
	if (f.getSigned())
		std::cout << _name << " : " << f.getName() << " already signed." << std::endl;
	else if (_grade > f.getG_toSign())
		std::cout << _name << " : My rank does not authorize me to sign -> " << f.getName() << std::endl;
	else if (_grade > f.getG_toSign())
		std::cout << _name << " : My rank does not authorize me to sign -> " << f.getName() << std::endl;
	else
		std::cout << _name << " : has the authorization to sign -> " << f.getName() << std::endl;
}

void	Bureaucrat::executeForm(const AForm& a) const {
	if (!a.getSigned())
		signForm(a);
	if (a.getSigned())
	{
		if (_grade > a.getG_toExec())
			std::cout << _name << " : My rank does not authorize me to exec -> " << a.getName() << std::endl;
		else if (_grade > a.getG_toExec())
			std::cout << _name << " : My rank does not authorize me to exec -> " << a.getName() << std::endl;
		else
			std::cout << _name << " : has the authorization to exec -> " << a.getName() << std::endl;
	}
}

void	Bureaucrat::increment() {
	if (_grade == 1)
		std::cout << "Maximum grade reached" << std::endl;
	else
		setGrade(_grade - 1);
}

void	Bureaucrat::decrement() {
	if (_grade == 150)
		std::cout << "Minimum grade reached" << std::endl;
	else
		setGrade(_grade + 1);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string n) : _name(n) {}

const char*	Bureaucrat::GradeTooHighException::what()	const throw() {
	static std::string ErrMsg = _name + " -> GradeTooHighException : grade given higher than 150.";
	return ErrMsg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string n) : _name(n) {}

const char*	Bureaucrat::GradeTooLowException::what()	const throw() {
	static std::string ErrMsg = _name + " -> GradeTooLowException : grade assigned less than 0.";
	return ErrMsg.c_str();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << "| Name : " << b.getName() << " | Grade : " << b.getGrade() << std::endl;
	return os;
}