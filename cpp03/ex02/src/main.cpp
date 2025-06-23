/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:14:52 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:14:52 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[33m"

int	main(void) {
	std::cout << YELLOW << "*** This tale is about to start ***" << RESET << std::endl;
	ClapTrap	ct("Clappy");
	ScavTrap	st("Scavvy");
	FragTrap	ft("Fraggy");
	FragTrap	twin(ft);
	std::cout << std::endl;

	std::cout << YELLOW << "*** The heroes assemble at dawn ***" << RESET << std::endl;
	ct.healthReport();
	st.healthReport();
	ft.healthReport();
	twin.healthReport();
	std::cout << std::endl;

	std::cout << YELLOW << "*** Clappy makes the first move and pokes the others ***" << RESET << std::endl;
	ct.attack(st.getName());
	st.takeDamage(ct.getAttackDamage());
	ct.attack(ft.getName());
	ft.takeDamage(ct.getAttackDamage());
	std::cout << std::endl;

	std::cout << YELLOW << "*** Scavvy loses patience and counterattacks ***" << RESET << std::endl;
	st.attack(ct.getName());
	ct.takeDamage(st.getAttackDamage());
	st.attack(ft.getName());
	ft.takeDamage(st.getAttackDamage());
	std::cout << std::endl;

	std::cout << YELLOW << "*** Fraggy (the twin) raises a hand in peace ***" << RESET << std::endl;
	twin.highFivesGuys();
	std::cout << std::endl;

	std::cout << YELLOW << "*** Scavy shrugs and takes guard at the northern gate ***" << RESET << std::endl;
	st.guardGate();
	std::cout << std::endl;

	std::cout << YELLOW << "*** Final status after the conflict ***" << RESET << std::endl;
	ct.healthReport();
	st.healthReport();
	ft.healthReport();
	twin.healthReport();
	std::cout << std::endl;

	std::cout << YELLOW << "*** Night falls... until next time! ***" << RESET << std::endl;

	return 0;
}
