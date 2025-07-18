/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:24:41 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 10:24:41 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request Form", 72, 45, "undefined target") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request Form", 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	RobotomyRequestForm::beExecuted(void) const {
	std::cout << "BzzzZZz... ";
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " failed to be robotomized." << std::endl;
}
