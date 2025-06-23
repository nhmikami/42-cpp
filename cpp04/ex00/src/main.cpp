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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

int main()
{
	{
		std::cout << GREEN << ">> CORRECT TEST" << RESET << std::endl;
		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();
		std::cout << std::endl;
	
		std::cout << j->getType() << " enters the playground" << std::endl;
		std::cout << i->getType() << " enters the playground" << std::endl;
		std::cout << meta->getType() << " enters the playground" << std::endl;
		std::cout << std::endl;
	
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;
	
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << RED << ">> WRONG TEST" << RESET << std::endl;
		const WrongAnimal*	wrongMeta = new WrongAnimal();
		const WrongAnimal*	wrongCat = new WrongCat();
		std::cout << std::endl;

		std::cout << wrongCat->getType() << " enters the playground" << std::endl;
		std::cout << wrongMeta->getType() << " enters the playground" << std::endl;
		std::cout << std::endl;

		wrongCat->makeSound();
		wrongMeta->makeSound();	
		std::cout << std::endl;

		delete wrongMeta;
		delete wrongCat;
	}
	return 0;
}
