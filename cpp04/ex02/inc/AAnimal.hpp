#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string		_type;
		
	public:
		AAnimal(void);
		AAnimal(const AAnimal& other);
		virtual ~AAnimal(void);

		AAnimal&	operator=(const AAnimal& other);
		
		virtual void	makeSound(void) const = 0;

		std::string		getType(void) const;
};

#endif
