/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:21:39 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:21:39 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "A cat has been created." << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "A cat has been cloned." << std::endl;
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << "A cat has been destroyed." << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "A cat has been assigned values from another cat." << std::endl;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << _type << ": Meooooooow!" << std::endl;
}

Brain*	Cat::getBrain(void) const {
	return _brain;
}
