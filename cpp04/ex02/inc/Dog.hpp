/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:21:03 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:21:03 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal {
	private:
		Brain*	_brain;

	public:
		Dog(void);
		Dog(const Dog& other);
		~Dog(void);

		Dog&	operator=(const Dog& other);
		
		void	makeSound(void) const;

		Brain*	getBrain(void) const;
};

#endif
