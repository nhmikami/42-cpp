/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:51 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:51 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void) {
	{
		std::cout << MAGENTA << ">> SUBJECT TEST" << RESET << std::endl;
		IMateriaSource*	src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter*	me = new Character("me");
		
		AMateria*	tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << std::endl;
		
		ICharacter*	bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		std::cout << MAGENTA << ">> GENERAL TESTS" << RESET << std::endl;
		std::cout << YELLOW << "* Learning materias *" << RESET << std::endl;
		IMateriaSource*	src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		std::cout << std::endl;

		std::cout << YELLOW << "* Creating materias from source *" << RESET << std::endl;
		AMateria*	ice1 = src->createMateria("ice");
		AMateria*	cure1 = src->createMateria("cure");
		AMateria*	unknown = src->createMateria("fire");
		std::cout << std::endl;

		std::cout << YELLOW << "* Equipping materias to character *" << RESET << std::endl;
		ICharacter*	hero = new Character("Hero");
		AMateria*	ice2 = ice1->clone();
		AMateria*	cure2 = cure1->clone();
		AMateria*	ice3 = ice1->clone();

		hero->equip(ice1);
		hero->equip(cure1);
		hero->equip(unknown);
		hero->equip(ice2);
		hero->equip(cure2);
		hero->equip(ice3);
		std::cout << std::endl;

		std::cout << YELLOW << "* Using all equipped materias *" << RESET << std::endl;
		ICharacter* target = new Character("Target");
		for (int i = 0; i < 5; ++i) {
			hero->use(i, *target);
		}
		std::cout << std::endl;

		std::cout << YELLOW << "* Unequipping materias *" << RESET << std::endl;
		for (int i = 0; i < 5; ++i) {
			hero->unequip(i);
		}

		delete hero;
		delete target;
		delete src;
	}
	std::cout << std::endl;
	{
		std::cout << MAGENTA << ">> DEEP COPY TEST" << RESET << std::endl;
		std::cout << YELLOW << "* Equipping original budddy *" << RESET << std::endl;
		Character*	original = new Character("Original");
		original->equip(new Ice());
		original->equip(new Cure());
		std::cout << std::endl;
		
		std::cout << YELLOW << "* Using materias from original *" << RESET << std::endl;
		ICharacter* dummy = new Character("Dummy");
		original->use(0, *dummy);
		original->use(1, *dummy);
		std::cout << std::endl;
		
		std::cout << YELLOW << "* Copying buddy and using materias from copy *" << RESET << std::endl;
		ICharacter*	copy = new Character(*original);
		copy->use(0, *dummy);
		copy->use(1, *dummy);
		std::cout << std::endl;

		std::cout << YELLOW << "* Unequipping copy *" << RESET << std::endl;
		copy->unequip(0);
		copy->use(0, *dummy);
		std::cout << std::endl;

		std::cout << YELLOW << "* Verifying independence *" << RESET << std::endl;
		original->use(0, *dummy);

		delete original;
		delete copy;
		delete dummy;
	}
	return 0;
}
