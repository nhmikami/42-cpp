/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:11 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:11 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class ICharacter;

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(const Cure& other);
		~Cure(void);
		
		Cure&	operator=(const Cure& other);
		
		AMateria*	clone(void) const;
		void	    use(ICharacter& target);
};

#endif
