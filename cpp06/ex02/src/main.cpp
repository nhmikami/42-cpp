/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:35:20 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/22 08:48:44 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void) {
	{
		std::cout << YELLOW << "* Identifying classes by pointer *" << RESET << std::endl;
		Base*	aPtr = new A();
		identify(aPtr);
		delete(aPtr);

		Base*	bPtr = new B();
		identify(bPtr);
		delete(bPtr);
		
		Base*	cPtr = new C();
		identify(cPtr);
		delete(cPtr);
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "* Identifying classes by reference *" << RESET << std::endl;
		A		a;
		Base&	aRef = a;
		identify(aRef);
		
		B		b;
		Base&	bRef = b;
		identify(bRef);
		
		C		c;
		Base&	cRef = c;
		identify(cRef);
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "* Identifying random classes *" << RESET << std::endl;
		Base*	base;
		for (int i = 0; i < 10; i++) {
			base = generate();
			identify(base);
			identify(*base);
			delete(base);
			std::cout << std::endl;
		}
	}
}
