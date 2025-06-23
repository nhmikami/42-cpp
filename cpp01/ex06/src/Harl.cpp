/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:08:00 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:08:00 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl showed up and is mad." << std::endl;
	std::cout << std::endl;
}
Harl::~Harl() {
	std::cout << "Harl left, still mad." << std::endl;
}

void	Harl::_debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. " << std::endl
			  << "I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::_info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl
			  << "You didn’t put enough bacon in my burger! " << std::endl
			  << "If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. " << std::endl
			  << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::_error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	startLevel = -1;
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			startLevel = i;
			break;
		}
	}

	switch (startLevel) {
		case 0:
			_debug();
			// fall through
		case 1:
			_info();
			// fall through
		case 2:
			_warning();
			// fall through
		case 3:
			_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
	}
	return ;
}
