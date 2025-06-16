#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(const Ice& other);
		Ice&	operator=(const Ice& other);
		~Ice(void);
		
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
