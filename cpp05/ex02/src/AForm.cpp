/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:23:02 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 10:23:02 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
	: _name("blank form"), _signed(false), _gradeToSign(150), _gradeToExec(150), _target("undefined target") {
	std::cout << "A default blank form has been created." << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _target(target) {
	if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << _name << " has been created. Grade to sign: " << _gradeToSign << ", grade to execute: " << _gradeToExec << "." << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _target(other._target) {
	std::cout << _name << " has been copied." << std::endl;
}

AForm::~AForm(void) {
	std::cout << _name << " has been destroyed." << std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	std::cout << _name << " has received status from another form." << std::endl;
	if (this != &other)
		_signed = other.getSignedStatus();
	return *this;
}

const std::string&	AForm::getName(void) const {
	return _name;
}

bool	AForm::getSignedStatus(void) const {
	return _signed;
}

int	AForm::getGradeToSign(void) const {
	return _gradeToSign;
}

int	AForm::getGradeToExec(void) const {
	return _gradeToExec;
}

const std::string&	AForm::getTarget(void) const {
	return _target;
}

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else if (_signed)
		throw FormAlreadySignedException();
	_signed = true;
}

void	AForm::execute(const Bureaucrat &b) const {
	if (!_signed)
		throw FormNotSignedException();
	else if (b.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	beExecuted();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}

const char*	AForm::FormAlreadySignedException::what() const throw(){
	return "form is already signed.";
}

const char*	AForm::FormNotSignedException::what() const throw(){
	return "form is not signed.";
}

std::ostream&	operator<<(std::ostream& out, const AForm& f) {
	out << f.getName();
	if (f.getSignedStatus())
		out << " is signed. ";
	else
		out << " is unsigned. ";
	out << "It requires grade " << f.getGradeToSign() << " to be signed and grade " 
		<< f.getGradeToExec() << " to be executed.";
	return out;
}
