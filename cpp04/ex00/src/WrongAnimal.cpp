#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("wrong animal") {
	std::cout << "A wrong animal has been created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "A wrong animal has been cloned." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "A wrong animal has been destroyed." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "A wrong animal has been assigned values from another wrong animal." << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << _type << ": *no sound*" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return _type;
}
