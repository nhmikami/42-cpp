/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:59:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/24 10:56:39 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void) {
	{
		std::cout << MAGENTA << ">> SUBJECT TESTS" << RESET << std::endl;
		int	a = 2;
		int	b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << MAGENTA << ">> ADDITIONAL TESTS" << RESET << std::endl;
		std::cout << YELLOW << "* Testing integers *" << RESET << std::endl; 
		int a = 2;
		int b = 3;
		std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		std::cout << std::endl;
		
		std::cout << YELLOW << "* Testing doubles *" << RESET << std::endl; 
		double c = 42.42;
		double d = 21.21;
		std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Testing chars *" << RESET << std::endl; 
		char e = 'a';
		char f = '*';
		std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
		::swap(e, f);
		std::cout << "After swap:  e = " << e << ", f = " << f << std::endl;
		std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
		std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Testing strings *" << RESET << std::endl; 
		std::string g = "hello";
		std::string h = "world";
		std::cout << "Before swap: g = " << g << ", h = " << h << std::endl;
		::swap(g, h);
		std::cout << "After swap:  g = " << g << ", h = " << h << std::endl;
		std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
		std::cout << "max(g, h) = " << ::max(g, h) << std::endl;
	}
	return 0;
}
