/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:22:27 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 10:21:19 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
		const std::string	_target;
	
	protected:
		virtual void		beExecuted(void) const = 0;
	
	public:
		AForm(void);
		AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target);
		AForm(const AForm& other);
		virtual ~AForm(void);

		AForm&	operator=(const AForm& other);
		
		const std::string&	getName(void) const;
		bool				getSignedStatus(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		const std::string&	getTarget(void) const;
		void				beSigned(const Bureaucrat& b);
		void				execute(const Bureaucrat& b) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& f);

#endif
