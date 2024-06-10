/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:55:00 by waziz             #+#    #+#             */
/*   Updated: 2024/05/29 16:34:41 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) {
	(void)other;
}

Intern&	Intern::operator=(const Intern& affect) {
	(void)affect;
	return (*this);
}

Intern::~Intern() {}

AForm*    Intern::createShrubbery(std::string target) { return (new ShrubberyCreationForm(target)); }
AForm*    Intern::createRobotomy(std::string target) { return (new RobotomyRequestForm(target)); }
AForm*    Intern::createPresidential(std::string target) { return (new PresidentialPardonForm(target)); }

AForm*    Intern::makeForm(std::string name, std::string target)
{
    for (size_t i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);
    
    std::string valid[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm*    (Intern::*FormCreator[3])(std::string target) = { &Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential };
    
    for (int i = 0; i < 3; i++)
        if (valid[i] == name)
            return ((this->*FormCreator[i])(target));
    throw NoValidException();
}

const char*		Intern::NoValidException::what() const throw() {
	return ("Intern : Invalid Form !");
}