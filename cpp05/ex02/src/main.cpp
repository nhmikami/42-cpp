/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:28:11 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/16 14:28:11 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	std::cout << MAGENTA << ">> BUREAUCRACY: THE KINGDOM EDITION" << RESET << std::endl;
	Bureaucrat	king("King I", 1);
	std::cout << std::endl;

	std::cout << YELLOW << "Chapter I – The Enchanted Garden Decree" << RESET << std::endl;
	try {
		Bureaucrat				gardener("Gardener", 100);
		ShrubberyCreationForm	shrub("home");
		std::cout << std::endl;

		std::cout << "- The Gardener seeks nature’s blessing" << std::endl;
		gardener.executeForm(shrub);
		std::cout << std::endl;
		std::cout << "- The King, benevolent as ever, blesses the form with his signature" << std::endl;		
		king.signForm(shrub);
		std::cout << std::endl;
		std::cout << "- Now with royal approval, the Gardener strikes again!" << std::endl;
		gardener.executeForm(shrub);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Chapter II – The Clockwork Petition" << RESET << std::endl;
	try {
		Bureaucrat			engineer("Engineer", 40);
		Bureaucrat			mechanic("Mechanic", 100);
		RobotomyRequestForm robot("Bender");
		std::cout << std::endl;

		std::cout << "- The Engineer dares to defy bureaucracy" << std::endl;
		engineer.executeForm(robot);
		std::cout << std::endl;
		std::cout << "- The King grants his approval, and Engineer asks the Mechanic to step forward" << std::endl;
		king.signForm(robot);
		mechanic.executeForm(robot);
		std::cout << std::endl;
		std::cout << "- The Engineer reluctantly gets his hands dirty and registers the execution log:" << std::endl;
		for (int i = 0; i < 10; i++) {
			engineer.executeForm(robot);
			std::cout << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Chapter III – The Royal Pardon Proclamation" << RESET << std::endl;
	try {
		Bureaucrat 				president("Mr. President", 6);
		PresidentialPardonForm	pardon("Ford Prefect");
		std::cout << std::endl;

		std::cout << "- A President attempts mercy without the seal" << std::endl;
		president.executeForm(pardon);
		std::cout << std::endl;
		std::cout << "- The King grants clemency — a second chance arises" << std::endl;
		king.signForm(pardon);
		president.executeForm(pardon);
		std::cout << std::endl;
		std::cout << "- Promotion granted, executive power unlocked" << std::endl;
		president.incrementGrade();
		std::cout << president << std::endl;
		president.executeForm(pardon);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << MAGENTA << "=== THE END ===" << RESET << std::endl;
	return 0;
}
