/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:58:49 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:06:13 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Zombie " << _name << " is born." << std::endl;
	return ;
}

Zombie::Zombie() {
	std::cout << "New zombie is born." << std::endl;
	return ;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " died." << std::endl;
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name) {
	_name = name;
}
