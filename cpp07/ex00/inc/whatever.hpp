/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/24 10:56:28 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

template <typename T>
void	swap(T& a, T& b) {
	T	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T&	min(const T& a, const T& b) {
	return (a < b) ? a : b;
}

template <typename T>
const T&	max(const T& a, const T& b) {
	return (a > b) ? a : b;
}

#endif
