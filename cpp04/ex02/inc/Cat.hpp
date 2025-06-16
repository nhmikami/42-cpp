#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal {
	private:
		Brain*	_brain;

	public:
		Cat(void);
		Cat(const Cat& other);
		~Cat(void);

		Cat&	operator=(const Cat& other);
		
		void	makeSound(void) const;

		Brain*	getBrain(void) const;
};

#endif
