/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:33 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:33 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("unknown") {
}

AMateria::AMateria(std::string const& type) : _type(type) {
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria(void) {
}

std::string const&	AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* attempts to use an unknown materia on " << target.getName() << " *" << std::endl;
}
