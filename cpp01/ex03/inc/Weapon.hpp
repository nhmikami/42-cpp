/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:06:57 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:06:57 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string	_type;
	
	public:
		Weapon(std::string type);
		~Weapon();
		
		const std::string&  getType(void) const;
		void				setType(std::string type);
};

#endif
