/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:59:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/22 18:11:45 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void) {
	int			intArray[] = {1, 2, 3, 4, 5};
	// double		doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	// char		charArray[] = {'a', 'b', 'c', 'd', 'e'};
	// std::string	stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << YELLOW << "* Integer Array *" << RESET << std::endl;
	iter(intArray, 5, print<int>);
	iter(intArray, 5, addOne<int>);
	iter(intArray, 5, print<int>);
	std::cout << std::endl;
	
	
	return 0;
}
