/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:55:34 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 15:21:08 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_toSign;
		const int			_toExec;

	public:
		Form();
		Form(const std::string n, const int toSign, const int toExec);
		Form(const Form& other);
		Form&	operator=(const Form& affect);
		~Form();

		std::string	getName() const;
		bool		getSigned() const;
		int			getG_toSign() const;
		int			getG_toExec() const;

		class	GradeTooHighException : public std::exception {
			private:
				std::string	_name;
			
			public:
				GradeTooHighException(std::string n);
				const char*	what()	const throw();
				~GradeTooHighException() throw() {};
		};

        class	GradeTooLowException : public std::exception {
			private:
				std::string			_name;
				int					_myGrade;
				const Form&			_f;
				const Bureaucrat*	_b;
	
			public:
				GradeTooLowException(std::string n, int G, const Form& Form, const Bureaucrat* Bur);
				const char*	what()	const throw();
				~GradeTooLowException() throw() {};
		};
		void	beSigned(Bureaucrat& autograph);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif