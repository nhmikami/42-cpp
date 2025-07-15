/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:19:23 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:19:23 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << GREEN << ">> CORRECT TEST" << RESET << std::endl;
		const Animal*	a = new Animal();
		const Animal*	d = new Dog();
		const Animal*	c = new Cat();
		std::cout << std::endl;
	
		std::cout << d->getType() << " enters the playground" << std::endl;
		std::cout << c->getType() << " enters the playground" << std::endl;
		std::cout << a->getType() << " enters the playground" << std::endl;
		std::cout << std::endl;
	
		d->makeSound();
		c->makeSound();
		a->makeSound();
		std::cout << std::endl;
	
		delete a;
		delete d;
		delete c;
	}
	std::cout << std::endl;
	{
		std::cout << RED << ">> WRONG TEST" << RESET << std::endl;
		const WrongAnimal*	wrongA = new WrongAnimal();
		const WrongAnimal*	wrongC = new WrongCat();
		std::cout << std::endl;

		std::cout << wrongC->getType() << " enters the playground" << std::endl;
		std::cout << wrongA->getType() << " enters the playground" << std::endl;
		std::cout << std::endl;

		wrongC->makeSound();
		wrongA->makeSound();	
		std::cout << std::endl;

		delete wrongA;
		delete wrongC;
	}
	return 0;
}
