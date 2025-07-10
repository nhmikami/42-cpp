/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:58:38 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:05:40 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		~Zombie();

		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif