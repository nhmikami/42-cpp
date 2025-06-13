#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap& other);

		void	highFivesGuys(void) const;
};

#endif
