/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:18:50 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:18:50 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string		_type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& other);
		
		void	makeSound(void) const;

		std::string		getType(void) const;
};

#endif
