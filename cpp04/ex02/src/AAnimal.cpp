#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("unknown animal") {
	std::cout << "An abstract animal has been created." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "An abstract animal has been cloned." << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "An abstract animal has been destroyed." << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other) {
	if (this != &other)
		_type = other._type;
	std::cout << "An abstract animal has been assigned values from another abstract animal." << std::endl;
	return *this;
}

std::string	AAnimal::getType(void) const {
	return _type;
}
