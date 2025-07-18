/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:07:25 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/18 14:07:26 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const std::string& name, int grade);
		ScalarConverter(const ScalarConverter& other);
		
		ScalarConverter&	operator=(const ScalarConverter& other);
		
	public:
		~ScalarConverter(void);

		static void  convert(const std::string& literal);

};

#endif
