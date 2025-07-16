/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:22:27 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/16 15:59:31 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Form {
	private:
		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;
		
	public:
		Form(void);
		Form(const std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		virtual ~Form(void);

		Form&	operator=(const Form& other);
		
		const std::string	getName(void) const;
		bool				getSignedStatus(void) const;
		const int			getGradeToSign(void) const;
		const int			getGradeToExec(void) const;
		void				beSigned(Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& f);

#endif
