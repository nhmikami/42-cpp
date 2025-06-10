/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:58:41 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/10 19:35:41 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	std::cout << "Creating zombie on the heap" << std::endl;
	Zombie* heap_zombie = newZombie("Heapasaurus");
	heap_zombie->announce();
	std::cout << std::endl;
	
	std::cout << "Creating zombie on the stack" << std::endl;
	randomChump("Stackzilla");
	std::cout << std::endl;

	std::cout << "Deleting zombie on the heap" << std::endl;
	delete heap_zombie;
	
	return 0;
}
