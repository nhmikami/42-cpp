/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:13:11 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:13:11 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	std::cout << YELLOW << "*** ClapTraps entering ***" << RESET << std::endl;
	ClapTrap ct1("CT-One");
	ClapTrap ct2("CT-Two");
	ClapTrap ct3;
	ct3 = ct2;
	ClapTrap ctClone(ct1);
	std::cout << std::endl;

	std::cout << YELLOW << "*** Warm-up session begins! ***" << RESET << std::endl;
	ct1.attack("Target-A");
	ct1.takeDamage(3);
	ct1.beRepaired(5);
	std::cout << std::endl;

	std::cout << YELLOW << "*** Energy-draining training montage ***" << RESET << std::endl;
	for (int i = 0; i < 11; i++) {
		ct2.attack("Dummy");
	}
	ct2.beRepaired(3);
	ct2.takeDamage(5);
	std::cout << std::endl;
	
	std::cout << YELLOW << "*** Deadly attack ***" << RESET << std::endl;
	ct3.takeDamage(12);
	ct3.attack("Spirit");
	ct3.beRepaired(5);
	std::cout << std::endl;

	std::cout << YELLOW << "*** ClapTraps leaving ***" << RESET << std::endl;

	return 0;
}
