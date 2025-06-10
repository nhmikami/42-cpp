/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:58:38 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/10 19:44:27 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();

    void    announce(void);
	void	setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif