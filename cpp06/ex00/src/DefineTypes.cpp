/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DefineTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:29:10 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/22 17:28:57 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DefineTypes.hpp"

bool	isChar(const std::string& str) {
	if (str.length() != 1 || !isprint(str[0]) || isdigit(str[0]))
		return false;
	
	return true;
}

bool	isInt(const std::string& str) {
	std::istringstream	iss(str);
	int	num;
	
	iss >> num;
	if (iss.fail() || !iss.eof())
		return false;
	
	return true;
}

bool	isFloat(const std::string& str) {
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf")
		return true;

	std::istringstream	iss(str);
	float	num;
	
	iss >> num;
	if (iss.fail() || iss.eof())
		return false;

	std::string	suffix;
	iss >> suffix;
	if (suffix != "f")
		return false;
	
	return true;
}

bool	isDouble(const std::string& str) {
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
		return true;

	std::istringstream	iss(str);
	double	num;
	
	iss >> num;
	if (iss.fail() || !iss.eof())
		return false;
	
	return true;
}
