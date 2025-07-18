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
#include "Intern.hpp"

int	main(void) {
	std::cout << MAGENTA << ">> BUREAUCRACY: THE KINGDOM EDITION" << RESET << std::endl;
	Bureaucrat	king("King I", 1);
	std::cout << std::endl;
	
	std::cout << YELLOW << "Chapter I – The Enchanted Garden Decree" << RESET << std::endl;
	try {
		Intern		intern;
		AForm*		shrub = intern.makeForm("shrubbery creation", "home");
		Bureaucrat	gardener("Gardener", 100);
		std::cout << std::endl;

		std::cout << "- The Gardener seeks nature’s blessing" << std::endl;
		gardener.executeForm(*shrub);
		std::cout << std::endl;
		std::cout << "- The King, benevolent as ever, blesses the form with his signature" << std::endl;		
		king.signForm(*shrub);
		std::cout << std::endl;
		std::cout << "- Now with royal approval, the Gardener strikes again!" << std::endl;
		gardener.executeForm(*shrub);
		std::cout << std::endl;

		delete shrub;
	}
	catch (std::exception& e) {
		std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Chapter II – The Clockwork Petition" << RESET << std::endl;
	try {
		Intern		intern;
		AForm*		robot = intern.makeForm("robotomy request", "Bender");
		Bureaucrat	engineer("Engineer", 40);
		Bureaucrat	mechanic("Mechanic", 100);
		std::cout << std::endl;

		std::cout << "- The Engineer dares to defy bureaucracy" << std::endl;
		engineer.executeForm(*robot);
		std::cout << std::endl;
		std::cout << "- The King grants his approval, and Engineer asks the Mechanic to step forward" << std::endl;
		king.signForm(*robot);
		mechanic.executeForm(*robot);
		std::cout << std::endl;
		std::cout << "- The Engineer reluctantly gets his hands dirty and registers the execution log:" << std::endl;
		for (int i = 0; i < 10; i++) {
			engineer.executeForm(*robot);
			std::cout << std::endl;
		}

		delete robot;
	}
	catch (std::exception& e) {
		std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Chapter III – The Royal Pardon Proclamation" << RESET << std::endl;
	try {
		Intern		intern;
		AForm*		pardon = intern.makeForm("presidential pardon", "Ford Prefect");
		Bureaucrat 	president("Mr. President", 6);
		std::cout << std::endl;

		std::cout << "- A President attempts mercy without the seal" << std::endl;
		president.executeForm(*pardon);
		std::cout << std::endl;
		std::cout << "- The King grants clemency — a second chance arises" << std::endl;
		king.signForm(*pardon);
		president.executeForm(*pardon);
		std::cout << std::endl;
		std::cout << "- Promotion granted, executive power unlocked" << std::endl;
		president.incrementGrade();
		std::cout << president << std::endl;
		president.executeForm(*pardon);
		std::cout << std::endl;

		delete pardon;
	}
	catch (std::exception& e) {
		std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Chapter IV – The Curious Case of the Phantom Form" << RESET << std::endl;
	try {
		Intern	intern;
		std::cout << std::endl;

		std::cout << "- With courage (and questionable training), the Intern attempts to conjure a legendary form..." << std::endl;
		AForm*	unknown = intern.makeForm("time travel request", "Past");
		std::cout << std::endl;

		if (unknown) {
			std::cout << "- Somehow, against all odds, it worked?!?" << std::endl;
			delete unknown;
		}
	}
	catch (std::exception& e) {
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << MAGENTA << "=== THE END ===" << RESET << std::endl;
	return 0;
}
