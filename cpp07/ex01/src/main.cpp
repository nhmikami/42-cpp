/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:59:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/23 01:19:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void) {
	int			intArray[] = {1, 2, 3, 4, 5};
	double		doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char		charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	strArray[] = {"one", "two", "three", "four", "five"};

	std::cout << YELLOW << "* Integer Array *" << RESET << std::endl;
	std::cout << "intArray before: ";
	iter(intArray, 5, printValue<int>);
	std::cout << std::endl;
	iter(intArray, 5, addOne<int>);
	std::cout << "intArray after: ";
	iter(intArray, 5, printValue<int>);
	std::cout << std::endl << std::endl;

	std::cout << YELLOW << "* Double Array *" << RESET << std::endl;
	std::cout << "doubleArray before: ";
	iter(doubleArray, 5, printValue<double>);
	std::cout << std::endl;
	iter(doubleArray, 5, half<double>);
	std::cout << "doubleArray after: ";
	iter(doubleArray, 5, printValue<double>);
	std::cout << std::endl << std::endl;

	std::cout << YELLOW << "* Char Array *" << RESET << std::endl;
	std::cout << "charArray before: ";
	iter(charArray, 5, printValue<char>);
	std::cout << std::endl;
	iter(charArray, 5, toUpper<char>);
	std::cout << "charArray after: ";
	iter(charArray, 5, printValue<char>);
	std::cout << std::endl << std::endl;
	
	std::cout << YELLOW << "* String Array *" << RESET << std::endl;
	std::cout << "strArray before: ";
	iter(strArray, 5, printValue<std::string>);
	std::cout << std::endl;
	iter(strArray, 5, append<std::string>);
	std::cout << "strArray after: ";
	iter(strArray, 5, printValue<std::string>);
	std::cout << std::endl;
	
	return 0;
}
