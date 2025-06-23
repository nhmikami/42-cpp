/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:07:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:07:05 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack(void) const {
	if (_weapon) {
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	} else {
		std::cout << _name << " attacks with their bare hands" << std::endl;
	}
	return ;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}
