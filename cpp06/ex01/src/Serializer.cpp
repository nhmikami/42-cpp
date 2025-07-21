/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:07:29 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/21 17:29:42 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer::~Serializer(void) {
}

Serializer&	Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr) {
	std::cout << "Data serialization complete!" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw) {
	std::cout << "Data deserialization complete!" << std::endl;
	return reinterpret_cast<Data*>(raw);
}
