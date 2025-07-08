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
		std::cout << YELLOW << "Enter command (ADD, SEARCH, EXIT): " << RESET;
		std::getline(std::cin, command);

		if (!std::cin) {
			std::cout << std::endl << "Goodbye!" << std::endl;
			break ;
		}
		if (command == "ADD") {
			phonebook.addContact();
			if (!std::cin) {
				std::cout << std::endl << "Goodbye!" << std::endl;
				break ;
			}
		}
		else if (command == "SEARCH") {
			phonebook.searchContact();
			if (!std::cin) {
				std::cout << std::endl << "Goodbye!" << std::endl;
				break ;
			}
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
