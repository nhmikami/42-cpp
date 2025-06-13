#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("without a name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	: _name(other.getName()), _hitPoints(other.getHitPoints()),
	  _energyPoints(other.getEnergyPoints()), _attackDamage(other.getAttackDamage()) {
	std::cout << "ClapTrap " << other.getName() << " has been cloned." << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap " << _name << " has been assigned values from ClapTrap " << other.getName() << std::endl;
	if (this != &other) {
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return *this;
}

std::string	ClapTrap::getName(void) const {
	return _name;
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return _attackDamage;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead and cannot attack." << std::endl;
		return ;
	}
	else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left to attack." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	else if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount
				  << " points of damage and dies." << std::endl;
	}
	else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount
				  << " points of damage. Remaining HP: " << _hitPoints << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left to repair." << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself by " << amount
			  << " points. Total HP: " << _hitPoints << std::endl;
}

void	ClapTrap::healthReport(void) const {
	std::cout << "ClapTrap " << _name << ": " 
			  << _hitPoints << " HP, "
			  << _energyPoints << " EP, "
			  << _attackDamage << " AD" << std::endl;
}
