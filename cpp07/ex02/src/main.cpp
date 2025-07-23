/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:59:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/23 11:40:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**)
{
	{
		std::cout << MAGENTA << ">> SUBJECT TESTS" << RESET << std::endl;
		Array<int>	numbers(MAX_VAL);
		int*		mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			const int	value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		
		try {
			numbers[-2] = 0;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		
		try {
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	std::cout << std::endl;
	{
		std::cout << MAGENTA << ">> ADDITIONAL TESTS" << RESET << std::endl;
		std::cout << YELLOW << "* a: default constructor (empty) *" << RESET << std::endl;
		Array<int>	a;
		std::cout << "a = " << a << ", size = " << a.size() << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* b: parametrized constructor with 5 elements *" << RESET << std::endl;
		Array<int>	b(5);
		std::cout << "b = " << b << ", size = " << b.size() << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* c: copy constructor *" << RESET << std::endl;
		Array<int>	c(b);
		std::cout << "c = " << c << ", size = " << c.size() << std::endl;
		std::cout << std::endl;

		std::cout << "- verifying deep copy" << std::endl;
		for (unsigned int i = 0; i < c.size(); i++)
			c[i] = (i + 1) * 10;
		std::cout << "b = " << b << ", size = " << b.size() << std::endl;
		std::cout << "c = " << c << ", size = " << c.size() << std::endl;
		std::cout << std::endl;
			

		std::cout << YELLOW << "* d: assignment operator *" << RESET << std::endl;
		Array<int> d;
		d = c;
		std::cout << "d = " << d << ", size = " << d.size() << std::endl;
		std::cout << std::endl;

		std::cout << "- verifying deep copy" << std::endl;
		for (unsigned int i = 0; i < c.size(); i++)
			c[i] = c[i] / 10;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* e: array of strings *" << RESET << std::endl;
		Array<std::string> e(3);
		e[0] = "Hello";
		e[1] = "World";
		e[2] = "!";
		std::cout << "e = " << e << ", size = " << e.size() << std::endl;
		std::cout << std::endl;

		try {
			std::cout << YELLOW << "* Testing access operator [] *" << RESET << std::endl;
			std::cout << "b[2] = " << b[2] << std::endl;
			std::cout << "e[2] = " << e[2] << std::endl;
			std::cout << "c[5] = " << c[5] << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	
	return 0;
}
