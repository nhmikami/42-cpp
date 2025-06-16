#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class ICharacter; // Forward declaration to avoid circular dependency

class AMateria {
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria(void);

		std::string	const&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
