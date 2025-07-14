/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:15:59 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:15:59 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {
	{
		std::cout << YELLOW << "*** Shinny confidently steps into the arena ***" << RESET << std::endl;
		DiamondTrap dt("Shinny");
		std::cout << std::endl;

		std::cout << YELLOW << "*** Initial health report ***" << RESET << std::endl;
		dt.healthReport();
		std::cout << std::endl;

		std::cout << YELLOW << "*** Brief introduction ***" << RESET << std::endl;
		dt.whoAmI();
		std::cout << std::endl;

		std::cout << YELLOW << "*** Shinny is showing off its abilities ***" << RESET << std::endl;
		dt.guardGate();
		dt.highFivesGuys();
		dt.attack("target");
		std::cout << std::endl;

		std::cout << YELLOW << "*** After attacking, Shinny feels a bit tired ***" << RESET << std::endl;
		dt.healthReport();
		std::cout << std::endl;

		std::cout << YELLOW << "*** Shinny is going to rest now ***" << RESET << std::endl;
	}
	return 0;
}
