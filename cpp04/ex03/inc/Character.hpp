#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define MAX_INVENTORY 4
#define MAX_FLOOR 42

class Character : public ICharacter {
	private:
        std::string	_name;
        AMateria*	_inventory[4];
        AMateria*   _floor[42];

    public:
		Character(void);
        Character(std::string const& name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character(void);

        const std::string&  getName(void) const;
        const AMateria*     getMateria(int idx) const;

        void		equip(AMateria* m);
        void        unequip(int idx);
        void        use(int idx, ICharacter& target);
};

#endif
