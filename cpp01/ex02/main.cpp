/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:58:41 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/11 01:41:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "Memory address of the string variable: " << &brain << std::endl;
	std::cout << "Memory address held by stringPTR:      " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:      " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Value of the string variable:          " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR:         " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:         " << stringREF << std::endl;
	
	return 0;
}
