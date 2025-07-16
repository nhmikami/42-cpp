/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:21:11 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:21:11 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Unknown animal") {
	std::cout << "An abstract animal has been created." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "An abstract animal has been cloned." << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "An abstract animal has been destroyed." << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other) {
	std::cout << "An abstract animal has been assigned values from another abstract animal." << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string	AAnimal::getType(void) const {
	return _type;
}
