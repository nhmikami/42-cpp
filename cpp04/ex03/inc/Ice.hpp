/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:14 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class ICharacter;

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(const Ice& other);
		~Ice(void);

		Ice&	operator=(const Ice& other);
		
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
