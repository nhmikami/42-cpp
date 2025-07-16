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
	: _name("blank form"), _signed(false), _gradeToSign(1), _gradeToExec(1) {
}

Form::Form(const std::string name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
}

Form::~Form(void) {
}

Form&	Form::operator=(const Form& other) {
	if (this != &other)
		_signed = other.getSignedStatus();
	return *this;
}

const std::string	Form::getName(void) const {
	return _name;
}

bool	Form::getSignedStatus(void) const {
	return _signed;
}

const int	Form::getGradeToSign(void) const {
	return _gradeToSign;
}

const int	Form::getGradeToExec(void) const {
	return _gradeToExec;
}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();	
	else
		_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
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
