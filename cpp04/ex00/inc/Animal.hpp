/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:18:36 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:18:36 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string		_type;
		
	public:
		Animal(void);
		Animal(const Animal& other);
		virtual ~Animal(void);

		Animal&	operator=(const Animal& other);
		
		virtual void	makeSound(void) const;

		std::string		getType(void) const;
};

#endif
