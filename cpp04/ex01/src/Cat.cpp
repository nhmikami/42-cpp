#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "A cat has been created." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
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
