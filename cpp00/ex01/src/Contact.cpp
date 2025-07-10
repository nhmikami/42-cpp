/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:59:01 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/10 15:59:01 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string	Contact::getFirstName() const {
	return _firstName;
}

std::string	Contact::getLastName() const {
	return _lastName;
}

std::string	Contact::getNickname() const {
	return _nickname;
}

std::string	Contact::_getInputData(std::string field) const {
	std::string	data;

	while (true) {
		std::cout << "Enter " << field << ": ";
		std::getline(std::cin, data);

		if (!std::cin) {
			std::cerr << RED << "Error reading input." << RESET << std::endl;
			return ("");
		}

		if (!data.empty())
			break ;

		std::cout << RED << "Field can't be empty. Please try again." << RESET << std::endl;
	}
	return (data);
}

int	Contact::setContactInfo() {
	_firstName = _getInputData("First Name");
	if (!std::cin)
		return 0;
	_lastName = _getInputData("Last Name");
	if (!std::cin)
		return 0;
	_nickname = _getInputData("Nickname");
	if (!std::cin)
		return 0;;
	_phoneNumber = _getInputData("Phone Number");
	if (!std::cin)
		return 0;
	_darkestSecret = _getInputData("Darkest Secret");
	if (!std::cin)
		return 0;
	std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
	return 1;
}

void	Contact::displayContactInfo() const {
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
	return ;
}
