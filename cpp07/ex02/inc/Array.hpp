/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/24 10:56:54 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

template <typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		~Array(void);

		Array&	operator=(const Array& other);

		unsigned int	size(void) const;
		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& arr);

#include "Array.tpp"

#endif
