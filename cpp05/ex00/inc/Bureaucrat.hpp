
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		virtual ~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat& other);
		
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

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
