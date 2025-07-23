/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:47 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:47 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(const Ice& other) : AMateria(other) {
}

Ice&	Ice::operator=(const Ice& other) {
	(void)other;
	return *this;
}

Ice::~Ice(void) {
}

AMateria*	Ice::clone(void) const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
