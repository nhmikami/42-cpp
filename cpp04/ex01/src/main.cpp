/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:20:42 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:20:42 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << MAGENTA << ">> ANIMALS" << RESET << std::endl;
		std::cout << YELLOW << "* Animals arrived at the park *" << RESET << std::endl;
		const int size = 4;
		Animal* animals[size];

		for (int i = 0; i < size; i++) {
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << std::endl;

		std::cout << YELLOW << "* The animals went wild! *" << RESET << std::endl;
		for (int i = 0; i < size; i++)
			animals[i]->makeSound();
		std::cout << std::endl;

		std::cout << YELLOW << "* The sun sets... it's time to say goodbye *" << RESET << std::endl;
		for (int i = 0; i < size; i++)
			delete animals[i];
	}
	std::cout << std::endl;
	{
		std::cout << MAGENTA << ">> DOGS" << RESET << std::endl;
		std::cout << YELLOW << "* Creating dog Snoopy with default ideas *" << RESET << std::endl;
		Dog Snoopy;

		Snoopy.getBrain()->setIdea(0, "Eat");
		Snoopy.getBrain()->setIdea(1, "Sleep");
		Snoopy.getBrain()->setIdea(2, "Play");
		std::cout << "Snoopy's ideas:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "- Idea " << i << ": " << Snoopy.getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Snoopy was cloned into dog Snuppy *" << RESET << std::endl;
		Dog Snuppy = Snoopy;
		std::cout << "Snuppy's ideas after cloning:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "- Idea " << i << ": " << Snuppy.getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Snoopy changed his ideas *" << RESET << std::endl;
		Snoopy.getBrain()->setIdea(0, "Eat more");
		Snoopy.getBrain()->setIdea(1, "Sleep more");
		Snoopy.getBrain()->setIdea(2, "Play more");
		std::cout << "Snoopy's new ideas:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "- Idea " << i << ": " << Snoopy.getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Snuppy didn't change his ideas *" << RESET << std::endl;
		std::cout << "Snuppy's ideas:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "- Idea " << i << ": " << Snuppy.getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Dogs ran off wagging their tails *" << RESET << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << MAGENTA << ">> CATS" << RESET << std::endl;
		std::cout << YELLOW << "* Creating cat Garfield with default ideas *" << RESET << std::endl;
		Cat Garfield;

		Garfield.getBrain()->setIdea(0, "Eat lasagna");
		Garfield.getBrain()->setIdea(1, "Ignore humans");
		Garfield.getBrain()->setIdea(2, "Sleep");
		std::cout << "Garfield's ideas:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "- Idea " << i << ": " << Garfield.getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Garfield was cloned into cat Nermal *" << RESET << std::endl;
		Cat Nermal = Garfield;
		std::cout << "Nermal's ideas after cloning:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "- Idea " << i << ": " << Nermal.getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Garfield changed his ideas *" << RESET << std::endl;
		Garfield.getBrain()->setIdea(0, "Eat lasagna again");
		Garfield.getBrain()->setIdea(1, "Ignore humans again");
		Garfield.getBrain()->setIdea(2, "Sleep again");
		std::cout << "Garfield's new ideas:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "- Idea " << i << ": " << Garfield.getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Nermal didn't change its ideas *" << RESET << std::endl;
		std::cout << "Nermal's ideas:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "- Idea " << i << ": " << Nermal.getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "* Cats walked away indifferently, of course *" << RESET << std::endl;
	}

	return 0;
}
