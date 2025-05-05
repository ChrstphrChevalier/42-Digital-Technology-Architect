/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:14:14 by waziz             #+#    #+#             */
/*   Updated: 2024/05/29 15:44:17 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : _name("Form Default"), _signed(false), _toSign(150), _toExec(150) {
	std::cout << "Form : constructeur called" << std::endl;
}

Form::Form(std::string n, const int toSign, const int toExec) : _name(n), _toSign(toSign), _toExec(toExec) {
	if (toSign < 1 || toExec < 1)
		throw	GradeTooLowException(_name, -42, *this, NULL);
	else if (toSign > 150 || toExec > 150)
		throw	GradeTooHighException(_name);
	_signed = false;
	std::cout << _name << " : constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _toSign(other._toSign), _toExec(other._toExec) {
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Copy to " << other._name << " completed." << std::endl;
}

Form&	Form::operator=(const Form& affect) {
	if (this != &affect)
		_signed = affect._signed;
	return (*this);
}

Form::~Form() {
	std::cout << _name << " : Destructor called" << std::endl;
}

std::string	Form::getName() const {
	return _name;
}

bool		Form::getSigned() const {
	return _signed;
}

int			Form::getG_toSign() const {
	return _toSign;
}

int			Form::getG_toExec() const {
	return _toExec;
}

void	Form::beSigned(Bureaucrat& autograph) {
	if (autograph.getGrade() <= _toSign && !_signed)
	{
		std::cout << autograph.getName() << " sign the form : " << this->_name << std::endl; 
		_signed = true;
	}
	else if (!_signed)
		throw GradeTooLowException(_name, autograph.getGrade(), *this, &autograph);
}

Form::GradeTooHighException::GradeTooHighException(std::string n) : _name(n) {}

const char*	Form::GradeTooHighException::what()	const throw() {
	static std::string ErrMsg = _name + " -> GradeTooHighException : grade given higher than 150.";
	return ErrMsg.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string n, int G, const Form& Form, const Bureaucrat* Bur) : _name(n), _myGrade(G), _f(Form) {
	if (Bur)
		_b = Bur;
}

const char*	Form::GradeTooLowException::what()	const throw() {
	if (_myGrade == -42)
	{
		static std::string ErrMsg = _b->getName() + " -> GradeTooLowException : grade assigned less than 0.";
		return ErrMsg.c_str();
	}
	else if (_myGrade > _f.getG_toSign())
	{
		static std::string ErrMsg = _b->getName() + " : GradeTooLowException : The rank of -> " + _f.getName() + " <- is too low to sign";
		return ErrMsg.c_str();
	}
	return NULL;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "| Name : " << f.getName() << " | Signed is : " << (f.getSigned() ? "true" : "false") << " | Grade to Sign : " << f.getG_toSign() << " | Grade to Exec : " << f.getG_toExec() << std::endl;
	return os;
}