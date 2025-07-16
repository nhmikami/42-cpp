
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("nameless"), _grade(150) {
	std::cout << "A default bureaucrat has been created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	else {
		_grade = grade;
		std::cout << "A bureaucrat named " << _name << " with grade " << _grade << " has been created." << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "A bureaucrat has been cloned." << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "A bureaucrat has been destroyed." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "A bureaucrat has been assigned values from another bureaucrat." << std::endl;
	if (this != &other)
		_grade = other.getGrade();
	return *this;
}

const std::string	Bureaucrat::getName(void) const {
	return _name;
}

int	Bureaucrat::getGrade(void) const {
	return _grade;
}

void	Bureaucrat::incrementGrade(void) {
	if (_grade <= HIGHEST_GRADE)
		throw GradeTooHighException();
	else {
		_grade--;
		std::cout << "Grade incremented to " << _grade  << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade >= LOWEST_GRADE)
		throw GradeTooLowException();
	else {
		_grade++;
		std::cout << "Grade decremented to " << _grade << std::endl;

	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
