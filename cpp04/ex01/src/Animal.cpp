/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:20:25 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:20:25 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Unknown animal") {
	std::cout << "An animal has been created." << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "An animal has been cloned." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "An animal has been destroyed." << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << "An animal has been assigned values from another animal." << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void	Animal::makeSound(void) const {
	std::cout << _type << ": *no sound*" << std::endl;
}

std::string	Animal::getType(void) const {
	return _type;
}
