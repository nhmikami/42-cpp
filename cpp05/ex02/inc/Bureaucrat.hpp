/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:28:01 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/16 14:28:01 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

class AForm;

class Bureaucrat {
	private:
		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;
		const std::string	_name;
		int					_grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat& other);
		
		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm& form);
		void				executeForm(const AForm& form) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);

#endif
