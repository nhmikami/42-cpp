/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:05 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define INVENTORY_SIZE 4
#define FLOOR_SIZE 42

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria*	_inventory[INVENTORY_SIZE];
		AMateria*	_floor[FLOOR_SIZE];

	public:
		Character(void);
		Character(std::string const& name);
		Character(const Character& other);
		~Character(void);
		
		Character&	operator=(const Character& other);

		const std::string&  getName(void) const;
		const AMateria*     getMateria(int idx) const;

		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter& target);
};

#endif
