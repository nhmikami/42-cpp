#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap " << _name << " has been created." << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << _name << " has been created." << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << other.getName() << " has been cloned." << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " has been destroyed." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap " << _name << " has been assigned values from FragTrap " << other.getName() << std::endl;
	if (this != &other) {
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return *this;
}

void	FragTrap::highFivesGuys(void) const {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name << " is already dead and cannot high five." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " is giving a high five!" << std::endl;
}
