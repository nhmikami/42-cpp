/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:24:38 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 10:24:38 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon Form", 25, 5, "undefined target") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	PresidentialPardonForm::beExecuted(void) const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
