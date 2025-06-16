#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
	private:
		Brain*	_brain;

	public:
		Dog(void);
		Dog(const Dog& other);
		~Dog(void);

		Dog&	operator=(const Dog& other);
		
		void	makeSound(void) const;

		Brain*	getBrain(void) const;
};

#endif
