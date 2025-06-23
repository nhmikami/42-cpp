/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:20:51 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:20:51 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string		_type;
		
	public:
		AAnimal(void);
		AAnimal(const AAnimal& other);
		virtual ~AAnimal(void);

		AAnimal&	operator=(const AAnimal& other);
		
		virtual void	makeSound(void) const = 0;

		std::string		getType(void) const;
};

#endif
