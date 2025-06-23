/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:06:54 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:06:54 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
		std::string	_name;
		Weapon*		_weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();
		
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);
};

#endif
