/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:20:30 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:20:30 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain initialized with fresh ideas!" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "A brain with brilliant ideas has been cloned." << std::endl;
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain(void) {
	std::cout << "Brain disassembled and all ideas vanished into thin air..." << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "A brain has been assigned ideas from another brain." << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

std::string	Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		return NULL;
	}
	return _ideas[index];
}

void	Brain::setIdea(int index, const std::string idea) {
	if (index < 0 || index >= 100) {
		return ;
	}
	_ideas[index] = idea;
}
