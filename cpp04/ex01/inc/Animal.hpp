/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:19:37 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:19:37 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

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
