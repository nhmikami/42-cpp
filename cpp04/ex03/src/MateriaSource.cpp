/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:56 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:56 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < MEMORY_SIZE; i++)
		_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < MEMORY_SIZE; i++) {
		if (other._memory[i])
			_memory[i] = other._memory[i]->clone();
		else
			_memory[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < MEMORY_SIZE; i++) {
			delete _memory[i];
			_memory[i] = NULL;
			if (other._memory[i])
				_memory[i] = other._memory[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < MEMORY_SIZE; i++) {
		if (_memory[i]) {
			delete _memory[i];
			_memory[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return ;
		
	for (int i = 0; i < MEMORY_SIZE; i++) {
		if (_memory[i] == NULL) {
			_memory[i] = m;
			std::cout << "Materia Source: learned new materia of type " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Materia Source: memory is full, cannot learn more materias" << std::endl;
	delete m;
	return ;
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < MEMORY_SIZE; i++) {
		if (_memory[i] && _memory[i]->getType() == type) {
			AMateria* newMateria = _memory[i]->clone();
			std::cout << "Materia Source: created materia of type " << type << std::endl;
			return newMateria;
		}
	}
	std::cout << "Materia Source: no materia of type " << type << " found, creation failed" << std::endl;
	return NULL;
}
