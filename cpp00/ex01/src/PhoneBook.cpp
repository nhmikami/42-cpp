/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:59:12 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/10 15:59:12 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0) {}

PhoneBook::~PhoneBook() {}

std::string	PhoneBook::_truncateData(const std::string str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

void	PhoneBook::addContact() {
	_contacts[_contactCount % 8].setContactInfo();
	_contactCount++;

	return ;
}

void	PhoneBook::searchContact() const {
	if (_contactCount == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	std::cout << "|" 
			  << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < _contactCount && i < 8; i++) {
		std::cout << "|" 
				  << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << _truncateData(_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << _truncateData(_contacts[i].getLastName()) << "|"
				  << std::setw(10) << _truncateData(_contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << std::endl;

	std::string	input;
	std::cout << "Enter the index to view contact's details: ";
	std::getline(std::cin, input);
	int	index = std::atoi(input.c_str());

	if (index < 1 || index > _contactCount || index > 8) {
		std::cout << RED << "Invalid index." << RESET << std::endl;
		return ;
	}

	_contacts[index - 1].displayContactInfo();
	return ;
}
