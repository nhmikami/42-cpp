/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayTypes.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:29:07 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/22 17:39:26 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayTypes.hpp"

void	displayChar(double literal) {
	if (literal > std::numeric_limits<char>::max() || literal < -std::numeric_limits<char>::max() || std::isnan(literal))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(literal)))
		std::cout << "char: non displayable" << std::endl;
	else
		std:: cout << "char: '" << static_cast<char>(literal) << "'" << std::endl;
}

void	displayInt(double literal) {
	if (literal > std::numeric_limits<int>::max() || literal < std::numeric_limits<int>::min() || std::isnan(literal))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(literal) << std::endl;
}

void	displayFloat(double literal) {
	if (std::isinf(literal))
		std::cout << "float: " << (literal > 0 ? "+inff" : "-inff") << std::endl;
	else if (literal > std::numeric_limits<float>::max() || literal < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(literal) << "f" << std::endl;
}

void	displayDouble(double literal) {
	if (std::isinf(literal))
		std::cout << "double: " << (literal > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(literal) << std::endl;
}
