/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:58:41 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/10 19:58:19 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	std::cout << "Creating horde of zombies on the heap" << std::endl;
	int	horde_size = 5;
	
	Zombie* horde = zombieHorde(horde_size, "Zombinário");

	for (int i = 0; i < horde_size; ++i)
		horde[i].announce();
	std::cout << std::endl;
		
	std::cout << "Deleting horde of zombies on the heap" << std::endl;
	delete[] horde;
	return 0;
}
