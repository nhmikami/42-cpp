/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:59:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/24 19:48:29 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main(void) {
	{
		std::cout << MAGENTA << ">> SUBJECT TESTS" << RESET << std::endl;
		Span	sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	std::cout << MAGENTA << ">> ADDITIONAL TESTS" << RESET << std::endl;
	{
		std::cout << YELLOW << "* Unitary span *" << RESET << std::endl;
		Span	sp(1);
		try {
			sp.addNumber(42);
			std::cout << "- Added a number to a unitary span and trying to add another one" << std::endl;
			sp.addNumber(21);
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{	
		std::cout << YELLOW << "* Shortest and longest span *" << RESET << std::endl;
		Span	sp(5);
		sp.addNumber(42);
		std::cout << "- Added one number to the span" << std::endl;
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "- Adding more numbers to the span" << std::endl;
		sp.addNumber(21);
		sp.addNumber(53);
		sp.addNumber(20);
		sp.addNumber(11);
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "* Range of numbers *" << RESET << std::endl;
		int	arr1[] = {1, 2, 3, 4, 5};
		int	arr2[] = {6, 7, 8, 9, 10};
		int	arr3[] = {11, 12, 13, 14, 15};
		std::vector<int>	vec(arr1, arr1 + sizeof(arr1) / sizeof(int));
		std::list<int>		lst(arr2, arr2 + sizeof(arr2) / sizeof(int));
		std::deque<int>		deq(arr3, arr3 + sizeof(arr3) / sizeof(int));
		
		Span	sp(15);
		try {
			sp.addRange(vec.begin(), vec.end());
			std::cout << "- Added a vector of numbers" << std::endl;
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		try {
			sp.addRange(lst.begin(), lst.end());
			std::cout << "- Added a list of numbers" << std::endl;
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		try {
			sp.addRange(deq.begin(), deq.end());
			std::cout << "- Added a deque of numbers" << std::endl;
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		try {
			std::cout << "- Trying to add vector of numbers again" << std::endl;
			sp.addRange(vec.begin(), vec.end());
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "* Large range of numbers! *" << RESET << std::endl;
		Span	sp(15000);
		
		std::vector<int>	largeVec;
		for (int i = 0; i < 5000; i++)
			largeVec.push_back(rand());
		
		std::list<int>	largeLst;
		for (int i = 0; i < 5000; i++)
			largeLst.push_back(rand());
			
		std::deque<int>	largeDeq;
		for (int i = 0; i < 5000; i++)
			largeDeq.push_back(rand());
			
		try {
			sp.addRange(largeVec.begin(), largeVec.end());
			std::cout << "- Added a large vector of numbers" << std::endl;
			std::cout << "Current span size: " << sp.size() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		try {
			sp.addRange(largeLst.begin(), largeLst.end());
			std::cout << "- Added a large list of numbers" << std::endl;
			std::cout << "Current span size: " << sp.size() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		try {
			sp.addRange(largeDeq.begin(), largeDeq.end());
			std::cout << "- Added a large deque of numbers" << std::endl;
			std::cout << "Current span size: " << sp.size() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		try {
			std::cout << "- Trying to add another large vector of numbers" << std::endl;
			sp.addRange(largeVec.begin(), largeVec.end());
			std::cout << "Current span size: " << sp.size() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
