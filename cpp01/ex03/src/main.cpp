/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:07:09 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:07:09 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main()
{
	{
		std::cout << "* HumanA:" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		std::cout << "* HumanB:" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
