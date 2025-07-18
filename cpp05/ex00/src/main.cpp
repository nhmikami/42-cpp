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

int	main(void) {
	{
		std::cout << YELLOW << "1. Default constructor" << RESET << std::endl;
		try {
			Bureaucrat b;
			std::cout << b << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "2. Parametrized constructor and grade change" << RESET << std::endl;
		try {
			Bureaucrat me("Nathalia", 50);
			std::cout << me << std::endl;
			std::cout << std::endl;

			std::cout << "- Incrementing grade" << std::endl;
			me.incrementGrade();
			std::cout << me << std::endl;
			std::cout << std::endl;

			std::cout << "- Decrementing grade" << std::endl;
			me.decrementGrade();
			std::cout << me << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "3. Invalid grade exceptions" << RESET << std::endl;
		try {
			std::cout << "- Trying to create Alice with grade 0" << std::endl;
			Bureaucrat a("Alice", 0);
			std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			std::cout << "- Trying to create Bob with grade 151" << std::endl;
			Bureaucrat b("Bob", 151);
			std::cout << b << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "4. Increment/Decrement boundary exceptions" << RESET << std::endl;
		try {
			Bureaucrat top("Big Boss", 1);
			std::cout << "- Trying to increment grade at upper boundary..." << std::endl;
			top.incrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat low("Paper Pusher", 150);
			std::cout << "- Trying to decrement grade at lower boundary..." << std::endl;
			low.decrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	return 0;
}
