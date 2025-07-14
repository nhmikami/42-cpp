/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:11:33 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:11:33 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	{
		std::cout << MAGENTA << "======= SUBJECT TEST =======" << RESET << std::endl;
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;		// a is 0
		std::cout << ++a << std::endl;		// a is now 1
		std::cout << a << std::endl;		// a is still 1
		std::cout << a++ << std::endl;		// a is still 1 at the moment of the output
		std::cout << a << std::endl;		// a is now 2
		std::cout << b << std::endl;		// b is 10.0f
		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << MAGENTA << "===== ADDITIONAL TESTS =====" << RESET << std::endl;
		Fixed		a;
		Fixed		b(5.05f);
		const Fixed	c(10);
		const Fixed	d(b);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Comparison tests *" << RESET << std::endl;
		std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
		std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
		std::cout << "a >= b: " << (a >= b ? "true" : "false") << std::endl;
		std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
		std::cout << "b == d: " << (b == d ? "true" : "false") << std::endl;
		std::cout << "b != c: " << (b != c ? "true" : "false") << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Arithmetic tests *" << RESET << std::endl;
		std::cout << "b + c = " << b + c << std::endl;
		std::cout << "b - c = " << b - c << std::endl;
		std::cout << "b * c = " << b * c << std::endl;
		std::cout << "b / c = " << b / c << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Increment / Decrement tests *" << RESET<< std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "++a = " << ++a << std::endl;	// Pre-increment
		std::cout << "a = " << a << std::endl;
		std::cout << "a++ = " << a++ << std::endl;	// Post-increment
		std::cout << "a = " << a << std::endl;
		std::cout << "--a = " << --a << std::endl;	// Pre-decrement
		std::cout << "a = " << a << std::endl;
		std::cout << "a-- = " << a-- << std::endl;	// Post-decrement
		std::cout << "a = " << a << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Min / Max tests *" << RESET << std::endl;
		std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
		std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
		std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
		std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
