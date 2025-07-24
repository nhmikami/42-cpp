/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/24 11:19:22 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"

template <typename T, typename F>
void	iter(T* array, size_t length, const F& function) {
	if (!array)
		return ;
		
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

/* Function templates */
template <typename T>
void	printValue(const T& value) {
	std::cout << value << " ";
}

template <typename T>
void	addOne(T& value) {
	value += 1;
}

template <typename T>
void	half(T& value) {
	value /= 2.0;
}

template <typename T>
void	toUpper(T& value) {
	value = std::toupper(value);
}

template <typename T>
void	append(T& value) {
	value += "!";
}

#endif
