/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:22 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 23:38:59 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("AForm -> ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm : Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("AForm -> ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm : Target constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
	setSigned(other.getSigned());
	std::cout << "ShrubberyCreationForm : Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& affect) {
	if (this != &affect)
		setSigned(affect.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm : Destructor called" << std::endl;
}

const std::string&	ShrubberyCreationForm::getTarget()	const {
	return _target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor)	const {
	if (!getSigned())
		throw GradeTooLowException(executor.getName(), "sign");
	else if (executor.getGrade() > getG_toExec())
		throw GradeTooLowException(executor.getName(), "exec");
	else
	{
		std::ofstream ofs(getTarget() + "_shrubbery");
		if (!ofs.is_open()) {
        	std::cerr << "Failed to create the file." << std::endl;
        	return;
    	}
		ofs << "                      ___" << std::endl;
		ofs << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
		ofs << "             ,-'          __,,-- \\" << std::endl;
		ofs << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
		ofs << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
		ofs << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
		ofs << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
		ofs << "     (     ,-'                  `." << std::endl;
		ofs << "      `._,'     _   _             ;" << std::endl;
		ofs << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
		ofs << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
		ofs << "        `--\'   \"Hb  HH  dF\"" << std::endl;
		ofs << "                \"Hb HH dF" << std::endl;
		ofs << "                 \"HbHHdF" << std::endl;
		ofs << "                  |HHHF" << std::endl;
		ofs << "                  |HHH|" << std::endl;
		ofs << "                  |HHH|" << std::endl;
		ofs << "                  |HHH|" << std::endl;
		ofs << "                  |HHH|" << std::endl;
		ofs << "                  dHHHb" << std::endl;
		ofs << "                .dFd|bHb.               o" << std::endl;
		ofs << "      o       .dHFdH|HbTHb.          o /" << std::endl;
		ofs << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
		ofs << "##########################################" << std::endl;
		ofs.close();
		std::cout << "Shrubbery created successfully in " << getTarget() << "_shrubbery" << std::endl;
	}
}
