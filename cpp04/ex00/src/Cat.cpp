#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "A cat has been created." << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "A cat has been cloned." << std::endl;
}

Cat::~Cat(void) {
	std::cout << "A cat has been destroyed." << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "A cat has been assigned values from another cat." << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << _type << ": Meooooooow!" << std::endl;
}
