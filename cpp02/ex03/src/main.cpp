/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:12:48 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:12:48 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout << YELLOW << "Triangle vertices: " << RESET
			  << "A(" << a.getX() << ", " << a.getY() << "), " 
			  << "B(" << b.getX() << ", " << b.getY() << "), "
			  << "C(" << c.getX() << ", " << c.getY() << ")"<< std::endl;
	std::cout << std::endl;

	Point	p1(1, 1);
	std::cout << YELLOW << "* p1(" << p1.getX() << ", " << p1.getY() << "): inside" << RESET << std::endl;
	std::cout << "p1 is " << (bsp(a, b, c, p1) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
	std::cout << std::endl;

	Point	p2(10, 10);
	std::cout << YELLOW << "* p2(" << p2.getX() << ", " << p2.getY() << "): outside" << RESET << std::endl;
	std::cout << "p2 is " << (bsp(a, b, c, p2) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
	std::cout << std::endl;

	Point	p3(0, 0);
	std::cout << YELLOW << "* p3(" << p3.getX() << ", " << p3.getY() << "): on vertex A" << RESET << std::endl;
	std::cout << "p3 is " << (bsp(a, b, c, p3) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
	std::cout << std::endl;

	Point	p4(5, 0);
	std::cout << YELLOW << "* p4(" << p4.getX() << ", " << p4.getY() << "): on edge" << RESET << std::endl;
	std::cout << "p4 is " << (bsp(a, b, c, p4) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
	std::cout << std::endl;

	Point	p5(0, 5);
	std::cout << YELLOW << "* p5(" << p5.getX() << ", " << p5.getY() << "): on edge" << RESET << std::endl;
	std::cout << "p5 is " << (bsp(a, b, c, p5) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
	std::cout << std::endl;

	Point	p6(-1, 1);
	std::cout << YELLOW << "* p6(" << p6.getX() << ", " << p6.getY() << "): outside" << RESET << std::endl;
	std::cout << "p6 is " << (bsp(a, b, c, p6) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;
	std::cout << std::endl;

	Point	p7(0.01f, 0.01f);
	std::cout << YELLOW << "* p7(" << p7.getX() << ", " << p7.getY() << "): inside, close to vertex A" << RESET << std::endl;
	std::cout << "p7 is " << (bsp(a, b, c, p7) ? "INSIDE" : "OUTSIDE") << " the triangle" << std::endl;

	return 0;
}
