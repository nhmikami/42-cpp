/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:06:47 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:06:47 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	private:
		std::string	_name;
		Weapon&		_weapon;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		
		void	attack(void) const;
};

#endif
