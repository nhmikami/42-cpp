/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:22:27 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 09:58:45 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private:
		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
		
	public:
		Form(void);
		Form(const std::string& name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		~Form(void);

		Form&	operator=(const Form& other);
		
		const std::string&	getName(void) const;
		bool				getSignedStatus(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		void				beSigned(const Bureaucrat& b);

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
};

std::ostream&	operator<<(std::ostream& out, const Form& f);

#endif
