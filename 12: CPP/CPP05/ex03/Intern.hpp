/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:14:45 by waziz             #+#    #+#             */
/*   Updated: 2024/05/29 16:36:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& affect);
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
		AForm* 	createShrubbery(std::string target);
		AForm*	createRobotomy(std::string target);
		AForm*	createPresidential(std::string target);

		class NoValidException : public std::exception {
			public:
				const char*	what() const throw();
		};
};


#endif