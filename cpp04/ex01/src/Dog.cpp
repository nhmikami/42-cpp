#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "A dog has been created." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "A dog has been cloned." << std::endl;
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "A dog has been destroyed." << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "A dog has been assigned values from another dog." << std::endl;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << _type << ": Woof! Woof!" << std::endl;
}

Brain*	Dog::getBrain(void) const {
	return _brain;
}
