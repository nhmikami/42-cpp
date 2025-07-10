/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:58:41 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:05:47 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	std::cout << YELLOW << "* Creating zombie on the heap *" << RESET << std::endl;
	Zombie* heap_zombie = newZombie("Heapasaurus");
	heap_zombie->announce();
	std::cout << std::endl;
	
	std::cout << YELLOW << "* Creating zombie on the stack *" << RESET << std::endl;
	randomChump("Stackzilla");
	std::cout << std::endl;

	std::cout << YELLOW << "* Deleting zombie from the heap *" << RESET << std::endl;
	delete heap_zombie;
	
	return 0;
}
