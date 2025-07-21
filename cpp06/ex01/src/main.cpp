/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:03:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/21 18:02:14 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data	originalData;
	originalData.str = "hello";
	originalData.num = 42;
	
	std::cout << YELLOW << "* Original data struct *" << RESET << std::endl;
	std::cout << "string: " << originalData.str  << ", ";
	std::cout << "number: " << originalData.num << std::endl;
	std::cout << "original pointer: " << &originalData << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "* Serialize data struct *" << RESET << std::endl;
	uintptr_t	raw = Serializer::serialize(&originalData);
	std::cout << "raw pointer: 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << "* Deserialize data struct *" << RESET << std::endl;
	Data*	back = Serializer::deserialize(raw);
	std::cout << "string: " << back->str << ", ";
	std::cout << "number: " << back->num << std::endl;
	std::cout << "deserialized pointer: " << back << std::endl; 
	std::cout << std::endl;

	if (back == &originalData)
		std::cout << GREEN << ">> Deserialized pointer matches original pointer" << RESET << std::endl;
	else
		std::cout << RED << ">> Deserialized pointer does NOT match original pointer" << RESET << std::endl;
	
	return 0;
}
