/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:18:44 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:18:44 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat& other);
		~Cat(void);

		Cat&	operator=(const Cat& other);
		
		void	makeSound(void) const;
};

#endif
