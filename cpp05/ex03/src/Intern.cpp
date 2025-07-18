#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "A default intern has been created." << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "An intern has been copied." << std::endl;
	*this = other;
}

Intern::~Intern(void) {
	std::cout << "An intern has been destroyed." << std::endl;
}

Intern&	Intern::operator=(const Intern& other) {
	std::cout << "A bureaucrat has been assigned values from another bureaucrat." << std::endl;
	(void)other;
	return *this;
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*makeFormPtr[3])(const std::string& target) = {
		&Intern::_makeShrubberyForm,
		&Intern::_makeRobotomyForm,
		&Intern::_makePresidentialForm
	};
	
	for (int i = 0; i < 3; i++) {
		if (name == forms[i]) {
			std::cout << "Intern creates " << name << " form." << std::endl;
			return (this->*makeFormPtr[i])(target);
		}
	}

	std::cout << "Intern doesn't know how to create " << name << " form." << std::endl;
	return NULL;
}

AForm*	Intern::_makeShrubberyForm(const std::string& target) {       	
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::_makeRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::_makePresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}
