/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:07:29 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/21 15:47:44 by naharumi         ###   ########.fr       */
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

void	ScalarConverter::convert(const std::string& input) {
	double	literal;
	
	if (isChar(input))
		literal = input[0];
	else if (isInt(input))
		literal = std::atoi(input.c_str());
	else if (isFloat(input))
		literal = std::atof(input.c_str());
	else if (isDouble(input))
		literal = std::atof(input.c_str());
	else {
		std::cout << "Error: unknown type" << std::endl;
		return ;
	}
	
	displayChar(literal);
	displayInt(literal);
	displayFloat(literal);
	displayDouble(literal);
}
