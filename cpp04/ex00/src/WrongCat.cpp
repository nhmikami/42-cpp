/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:19:31 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:19:31 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "A wrong cat has been created." << std::endl;
	_type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "A wrong cat has been cloned." << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "A wrong cat has been destroyed." << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << "A wrong cat has been assigned values from another wrong cat." << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << _type << ": Meooooooow!" << std::endl;
}
