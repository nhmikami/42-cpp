/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:13:37 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:13:37 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[33m"

int	main(void) {
	std::cout << YELLOW << "*** Initializing units in binary wasteland ***" << RESET << std::endl;
	ClapTrap basic("Byte");
	ScavTrap sentinel("Gatekeeper");
	std::cout << std::endl;

	std::cout << YELLOW << "*** System diagnostics report ***" << RESET << std::endl;
	basic.healthReport();
	sentinel.healthReport();
	std::cout << std::endl;

	std::cout << YELLOW << "*** Byte tests its attack routine on Gatekeeper! ***" << RESET << std::endl;
	basic.attack(sentinel.getName());
	sentinel.takeDamage(basic.getAttackDamage());
	std::cout << std::endl;

	std::cout << YELLOW << "*** Gatekeeper retaliates with precision! ***" << RESET << std::endl;
	sentinel.attack(basic.getName());
	basic.takeDamage(sentinel.getAttackDamage());
	std::cout << std::endl;

	std::cout << YELLOW << "*** Gatekeeper activates defense protocol ***" << RESET << std::endl;
	sentinel.guardGate();
	std::cout << std::endl;

	std::cout << YELLOW << "*** Status after the skirmish ***" << RESET << std::endl;
	basic.healthReport();
	sentinel.healthReport();
	std::cout << std::endl;

	std::cout << YELLOW << "*** The cycle ends... for now. ***" << RESET << std::endl;

	return 0;
}
