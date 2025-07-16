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
			Bureaucrat a("Alice", 50);
			std::cout << a << std::endl;

			a.incrementGrade();
			std::cout << a << std::endl;

			a.decrementGrade();
			std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}

	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "3. Invalid grade exceptions" << RESET << std::endl;
		try {
			std::cout << "Trying to create Alice with grade 0" << std::endl;
			Bureaucrat a("Alice", 0);
			std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
		
		try {
			std::cout << "Trying to create Bob with grade 151" << std::endl;
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
			Bureaucrat top("TopBureaucrat", 1);
			std::cout << GREEN << "Created: " << RESET << top << std::endl;
			std::cout << YELLOW << "Trying to increment grade at upper boundary..." << RESET << std::endl;
			top.incrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
		
		try {
			Bureaucrat low("LowBureaucrat", 150);
			std::cout << GREEN << "Created: " << RESET << low << std::endl;
			std::cout << YELLOW << "Trying to decrement grade at lower boundary..." << RESET << std::endl;
			low.decrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	return 0;
}