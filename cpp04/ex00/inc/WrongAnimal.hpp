#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string		_type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& other);
		
		void	makeSound(void) const;

		std::string		getType(void) const;
};

#endif
