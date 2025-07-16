/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:37 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:37 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {
}

Cure::Cure(const Cure& other) : AMateria(other) {
}

Cure&	Cure::operator=(const Cure& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

Cure::~Cure(void) {
}

AMateria*	Cure::clone(void) const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
