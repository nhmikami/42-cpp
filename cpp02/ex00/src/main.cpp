/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:09:43 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:09:43 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	std::cout << YELLOW << "* Default constructor *" << RESET << std::endl;
	Fixed	a;
	std::cout << std::endl;

	std::cout << YELLOW << "* Copy constructor *" << RESET << std::endl;
	Fixed	b(a);
	std::cout << std::endl;

	std::cout << YELLOW << "* Default constructor + Assignment operator *" << RESET << std::endl;
	Fixed	c;
	c = b;
	std::cout << std::endl;

	std::cout << YELLOW << "* getRawBits *" << RESET << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "* setRawBits *" << RESET << std::endl;
	a.setRawBits(42);
	b.setRawBits(21);
	c.setRawBits(84);
	std::cout << std::endl;

	std::cout << YELLOW << "* getRawBits *" << RESET << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "* End *" << RESET << std::endl;
	return 0;
}
