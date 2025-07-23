/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:44 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:44 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("nameless") {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < FLOOR_SIZE; i++)
		_floor[i] = NULL;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < FLOOR_SIZE; i++)
		_floor[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < FLOOR_SIZE; i++) {
		_floor[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other.getName();
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			delete _inventory[i];
			_inventory[i] = NULL;
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
		for (int i = 0; i < FLOOR_SIZE; i++) {
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
	return *this;
}

Character::~Character(void) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < FLOOR_SIZE; i++) {
		if (_floor[i]) {
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
}

const std::string&	Character::getName(void) const {
	return _name;
}

const AMateria*	Character::getMateria(int idx) const {
	if (idx < 0 || idx >= INVENTORY_SIZE) {
		std::cout << "Invalid index." << std::endl;
		return NULL;
	}
	return _inventory[idx];
}

void	Character::equip(AMateria* m) {
	if (!m) {
		std::cout << _name << ": unknown materia, cannot equip materia" << std::endl;
		return ;
	}

	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << _name << ": equipped " << m->getType() << " materia in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << _name << ": inventory is full, cannot equip more materias" << std::endl;
	delete m;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= INVENTORY_SIZE) {
		std::cout << _name << ": invalid index, cannot unequip materia" << std::endl;
		return ;
	}
	else if (!_inventory[idx]) {
		std::cout << _name << ": no materia to unequip" << std::endl;
		return ;
	}

	for (int i = 0; i < FLOOR_SIZE; i++) {
		if (_floor[i] == NULL) {
			_floor[i] = _inventory[idx];
			_inventory[idx] = NULL;
			std::cout << _name << ": unequipped " << _floor[i]->getType() << " materia"<< std::endl;
			return ;
		}
	}
	std::cout << _name << ": no space on the floor, could not unequip materia " << _inventory[idx]->getType() << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= INVENTORY_SIZE) {
		std::cout << _name << ": invalid index, cannot use materia" << std::endl;
		return;
	}
	else if (!_inventory[idx]) {
		std::cout << _name << ": no materia to use" << std::endl;
		return;
	}

	std::cout << _name << ": ";
	_inventory[idx]->use(target);
}
