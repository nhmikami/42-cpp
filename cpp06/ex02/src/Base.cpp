/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:16:48 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/22 08:59:26 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {
}

Base*	generate(void) {
	int random = rand() % 3;
	
	switch (random) {
		case 0:
			std::cout << "> Generated A class" << std::endl;
			return new A();
		case 1:
			std::cout << "> Generated B class" << std::endl;
			return new B();
		case 2:
			std::cout << "> Generated C class" << std::endl;
			return new C();
		default:
			return NULL; 
	}
}

void	identify(Base* p) {
	std::cout << "Pointed class is ";
	if (dynamic_cast<A*>(p))
		std::cout << "of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "of type C" << std::endl;
	else
		std::cout << "of unknown type" << std::endl;
}

void	identify(Base& p) {
	std::cout << "Referenced class is ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "of type A" << std::endl;
		return ;
	}
	catch (std::exception &) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "of type B" << std::endl;
		return ;
	}
	catch (std::exception &) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "of type C" << std::endl;
		return ;
	}
	catch (std::exception &) {
		std::cout << "of unknown type" << std::endl;
	}
}
