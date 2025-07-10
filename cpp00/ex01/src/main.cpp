/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:59:07 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/10 15:59:07 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {
	PhoneBook	phonebook;
	std::string	command;

	while (true) {
		if (!std::cin) {
			std::cout << "Goodbye!" << std::endl;
			break ;
		}

		std::cout << YELLOW << "Enter command (ADD, SEARCH, EXIT): " << RESET;
		std::getline(std::cin, command);

		if (command == "ADD") {
			phonebook.addContact();
		}
		else if (command == "SEARCH") {
			phonebook.searchContact();
		}
		else if (command == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else
			std::cout << RED << "Invalid command." << RESET << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
