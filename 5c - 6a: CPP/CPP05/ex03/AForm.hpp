/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:55:34 by waziz             #+#    #+#             */
/*   Updated: 2024/05/27 15:21:08 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_toSign;
		const int			_toExec;

	public:
		AForm();
		AForm(const std::string n, const int toSign, const int toExec);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& affect);
		virtual ~AForm();

		std::string	getName() const;
		bool		getSigned() const;
		int			getG_toSign() const;
		int			getG_toExec() const;

		void		setSigned(bool s);

		virtual const	std::string& getTarget() const = 0;
		virtual 		void	execute(const Bureaucrat& executor) const = 0;

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
				std::string 		_which;
	
			public:
				GradeTooLowException(std::string n, std::string which);
				const char*	what()	const throw();
				~GradeTooLowException() throw() {};
		};
		void	beSigned(Bureaucrat& autograph);
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif