/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:59:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/24 16:36:47 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main(void) {
	int	arr[] = {10, 20, 30, 40, 50};
	
	std::cout << YELLOW << "* Vector container *" << RESET << std::endl;
	std::vector<int>	vec(arr, arr + sizeof(arr) / sizeof(int));
	try {
		std::vector<int>::iterator	it;
		std::cout << "vector = {10, 20, 30, 40, 50}" << std::endl;
		std::cout << "- Searching for 10" << std::endl;
		it = easyfind(vec, 10);
		std::cout << "Found value: " << *it << std::endl;

		std::cout << "- Searching for 100" << std::endl;
		it = easyfind(vec, 100);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "* List container *" << RESET << std::endl;
	std::list<int>	lst(arr, arr + sizeof(arr) / sizeof(int));
	try {
		std::list<int>::iterator	it;
		std::cout << "list = {10, 20, 30, 40, 50}" << std::endl;
		std::cout << "- Searching for 30" << std::endl;
		it = easyfind(lst, 30);
		std::cout << "Found value: " << *it << std::endl;

		std::cout << "- Searching for 100" << std::endl;
		it = easyfind(lst, 100);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "* Deque container *" << RESET << std::endl;
	std::deque<int>	deq(arr, arr + sizeof(arr) / sizeof(int));
	try {
		std::deque<int>::iterator	it;
		std::cout << "deque = {10, 20, 30, 40, 50}" << std::endl;
		std::cout << "- Searching for 50" << std::endl;
		it = easyfind(deq, 50);
		std::cout << "Found value: " << *it << std::endl;

		std::cout << "- Searching for 100" << std::endl;
		it = easyfind(deq, 100);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
