/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:39:42 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/16 15:39:42 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: _name("blank form"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "A default blank form has been created." << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << _name << " has been created. Grade to sign: " << _gradeToSign << ", grade to execute: " << _gradeToExec << "." << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	std::cout << "A form has been copied." << std::endl;
}

Form::~Form(void) {
	std::cout << "A form has been destroyed." << std::endl;
}

Form&	Form::operator=(const Form& other) {
	std::cout << "A form has received status from another form." << std::endl;
	if (this != &other)
		_signed = other.getSignedStatus();
	return *this;
}

const std::string&	Form::getName(void) const {
	return _name;
}

bool	Form::getSignedStatus(void) const {
	return _signed;
}

int	Form::getGradeToSign(void) const {
	return _gradeToSign;
}

int	Form::getGradeToExec(void) const {
	return _gradeToExec;
}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else if (_signed)
		throw FormAlreadySignedException();
	_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}

const char*	Form::FormAlreadySignedException::what() const throw(){
	return "form is already signed.";
}

std::ostream&	operator<<(std::ostream& out, const Form& f) {
	out << f.getName();
	if (f.getSignedStatus())
		out << " is signed. ";
	else
		out << " is unsigned. ";
	out << "It requires grade " << f.getGradeToSign() << " to be signed and grade " 
		<< f.getGradeToExec() << " to be executed.";
	return out;
}
