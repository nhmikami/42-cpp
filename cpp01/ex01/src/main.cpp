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

	std::cout << YELLOW << "* Creating horde of " << horde_size << " zombies on the heap *" << RESET << std::endl;
	Zombie* horde = zombieHorde(horde_size, "OompaLoompa");
	std::cout << std::endl;

	std::cout << YELLOW << "* The horde is announcing itself! *" << RESET << std::endl;
	for (int i = 0; i < horde_size; i++)
		horde[i].announce();
	std::cout << std::endl;
		
	std::cout << YELLOW << "* Deleting zombie horde from the heap *" << RESET << std::endl;
	delete[] horde;
	return 0;
}
