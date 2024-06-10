/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:14:14 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 15:20:59 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : _name("AForm Default"), _signed(false), _toSign(150), _toExec(150) {
	std::cout << "AForm : constructeur called" << std::endl;
}

AForm::AForm(std::string n, const int toSign, const int toExec) : _name(n), _toSign(toSign), _toExec(toExec) {
	if (toSign < 1 || toExec < 1)
		throw	GradeTooLowException(_name, "init");
	if (toSign > 150 || toExec > 150)
		throw	GradeTooHighException(_name);
	_signed = false;
	std::cout << _name << " : constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _toSign(other._toSign), _toExec(other._toExec) {
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Copy to " << other._name << " completed." << std::endl;
}

AForm&	AForm::operator=(const AForm& affect) {
	if (this != &affect)
		_signed = affect._signed;
	return (*this);
}

AForm::~AForm() {
	std::cout << _name << " : Destructor called" << std::endl;
}

std::string	AForm::getName() const {return _name;}

bool		AForm::getSigned() const {return _signed;}

int			AForm::getG_toSign() const {return _toSign;}

int			AForm::getG_toExec() const {return _toExec;}

void		AForm::setSigned(bool s) {_signed = s;}

void	AForm::beSigned(Bureaucrat& autograph) {
	if (autograph.getGrade() <= _toSign && !_signed)
	{
		std::cout << autograph.getName() << " sign the form : " << this->_name << std::endl; 
		_signed = true;
	}
	else if (!_signed)
		throw GradeTooLowException(autograph.getName(), "sign");
}

AForm::GradeTooHighException::GradeTooHighException(std::string n) : _name(n) {}

const char*	AForm::GradeTooHighException::what()	const throw() {
	static std::string ErrMsg = _name + " -> GradeTooHighException : grade given higher than 150.";
	return ErrMsg.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(std::string n, std::string which) : _name(n), _which(which) {}

const char*	AForm::GradeTooLowException::what()	const throw() {
	if (_which == "init")
	{
		static std::string ErrMsg = _name + " -> GradeTooLowException : grade assigned less than 0.";
		return ErrMsg.c_str();
	}
	else if (_which == "sign")
	{
		static std::string ErrMsg = _name + " : GradeTooLowException : The rank is too low to sign";
		return ErrMsg.c_str();
	}
	else if (_which == "exec")
	{
		static std::string ErrMsg = _name + " : GradeTooLowException : The rank is too low to exec";
		return ErrMsg.c_str();
	}
	return NULL;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "| Name : " << f.getName() << " | Signed is : " << (f.getSigned() ? "true" : "false") << " | Grade to Sign : " << f.getG_toSign() << " | Grade to Exec : " << f.getG_toExec() << std::endl;
	return os;
}