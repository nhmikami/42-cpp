/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:58:41 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:06:11 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	int	horde_size = 5;

	std::cout << "* Creating horde of " << horde_size << " zombies on the heap" << std::endl;
	Zombie* horde = zombieHorde(horde_size, "OompaLoompa");
	std::cout << std::endl;

	std::cout << "* The horde is announcing itself!" << std::endl;
	for (int i = 0; i < horde_size; i++)
		horde[i].announce();
	std::cout << std::endl;
		
	std::cout << "* Deleting zombie horde from the heap" << std::endl;
	delete[] horde;
	return 0;
}
