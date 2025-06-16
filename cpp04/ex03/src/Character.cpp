#include "Character.hpp"

Character::Character(void) : _name("nameless") {
	for (int i = 0; i < MAX_INVENTORY; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_FLOOR; i++)
		_floor[i] = NULL;
}

Character::Character(std::string const& name) : _name(name) {
	for (int i = 0; i < MAX_INVENTORY; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_FLOOR; i++)
		_floor[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_FLOOR; i++) {
		if (other._floor[i])
			_floor[i] = other._floor[i]->clone();
		else
			_floor[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < MAX_INVENTORY; i++) {
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		for (int i = 0; i < MAX_FLOOR; i++) {
			delete _floor[i];
			if (other._floor[i])
				_floor[i] = other._floor[i]->clone();
			else
				_floor[i] = NULL;
		}
	}
	return *this;
}

Character::~Character(void) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		delete _inventory[i];
		_inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_FLOOR; i++) {
		delete _floor[i];
		_floor[i] = NULL;
	}
}

const std::string& Character::getName(void) const {
	return _name;
}

const AMateria* Character::getMateria(int idx) const {
	if (idx < 0 || idx >= MAX_INVENTORY) {
		std::cout << "Invalid index." << std::endl;
		return NULL;
	}
	return _inventory[idx];
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << "Equipped materia: " << m->getType() << " to " << _name << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip more materias." << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_INVENTORY || !_inventory[idx]) {
		std::cout << "Invalid index or no materia to unequip." << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_FLOOR - 1; i++) {
		if (_floor[i] == NULL) {
			_floor[i] = _inventory[idx];
			_inventory[idx] = NULL;
			std::cout << "Unequipped materia: " << _floor[i]->getType() << " from " << _name << std::endl;
			return ;
		}
	}
	std::cout << "Could not unequip materia " << _inventory[idx]->getType()
			  << ": no space on the floor!" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= MAX_INVENTORY || !_inventory[idx]) {
		std::cout << "Invalid index or no materia to use." << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
