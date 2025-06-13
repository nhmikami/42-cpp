#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap& other);

        void    attack(const std::string& target);
		void	whoAmI(void) const;
};

#endif
