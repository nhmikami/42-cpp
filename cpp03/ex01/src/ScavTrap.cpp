/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:13:42 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:13:42 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap " << _name << " has been created." << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << _name << " has been created." << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << other.getName() << " has been cloned." << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " has been destroyed." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap " << _name << " has been assigned values from ScavTrap " << other.getName() << std::endl;
	if (this != &other) {
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is already dead and cannot attack." << std::endl;
		return ;
	}
	else if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no energy points left to attack." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	return ;
}

void	ScavTrap::guardGate(void) const {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is already dead and cannot guard the gate." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode." << std::endl;
}
