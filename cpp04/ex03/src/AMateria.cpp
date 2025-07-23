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
#include "ICharacter.hpp"

AMateria::AMateria(void) : _type("unknown") {
}

AMateria::AMateria(const std::string& type) : _type(type) {
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
}

AMateria&	AMateria::operator=(const AMateria& other) {
	(void)other;
	return *this;
}

AMateria::~AMateria(void) {
}

const std::string&	AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* attempts to use an unknown materia on " << target.getName() << " *" << std::endl;
}
