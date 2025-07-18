/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:07:29 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 14:10:22 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
	return *this;
}

void    ScalarConverter::convert(const std::string& literal) {
    
}
