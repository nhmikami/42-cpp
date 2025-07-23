/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:59:05 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/23 20:34:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int	main(void) {
	{
		std::cout << MAGENTA << ">> SUBJECT TESTS" << RESET << std::endl;
		std::cout << YELLOW << "* Testing MutantStack *" << RESET << std::endl;
		MutantStack<int>	mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int>	s(mstack);
		std::cout << std::endl;

		std::cout << YELLOW << "* Testing list *" << RESET << std::endl;
		std::list<int>	lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator	itl = lst.begin();
		std::list<int>::iterator	itel = lst.end();
		++itl;
		--itl;
		while (itl != itel) {
			std::cout << *itl << std::endl;
			++itl;
		}
		
	}
	std::cout << std::endl;
	{
		std::cout << MAGENTA << ">> ADDITIONAL TESTS" << RESET << std::endl;
		std::cout << YELLOW << "* MutantStack of char list *" << RESET << std::endl;
		MutantStack<char, std::list<char> >	mstack;
		mstack.push('a');
		mstack.push('b');
		mstack.push('c');
		mstack.push('d');
		mstack.push('e');
		std::cout << "- Iterate over stack: ";
		MutantStack<char, std::list<char> >::iterator	it = mstack.begin();
		MutantStack<char, std::list<char> >::iterator	ite = mstack.end();
		while (it != ite) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "top element: " << mstack.top() << std::endl;
		std::cout << std::endl;
		
		std::cout << "- Pop top element" << std::endl;
		mstack.pop();
		std::cout << "new size: " << mstack.size() << std::endl;
		std::cout << "top element: " << mstack.top() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "* MutantStack of int vector *" << RESET << std::endl;
		MutantStack<int, std::vector<int> >	mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		std::cout << "- Reverse iterate over stack: ";
		MutantStack<int, std::vector<int> >::reverse_iterator	revIt = mstack.rbegin();
		MutantStack<int, std::vector<int> >::reverse_iterator	revIte = mstack.rend();
		while (revIt != revIte) {
			std::cout << *revIt << " ";
			revIt++;
		}
		std::cout << std::endl;
		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "top element: " << mstack.top() << std::endl;
		std::cout << std::endl;
		
		std::cout << "- Pop top element" << std::endl;
		mstack.pop();
		std::cout << "new size: " << mstack.size() << std::endl;
		std::cout << "top element: " << mstack.top() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "* Deep copy *" << RESET << std::endl;
		MutantStack<std::string>	mstack1;
		mstack1.push("hello");

		MutantStack<std::string>	mstack2(mstack1);
		mstack2.push("world");

		std::cout << "MutantStack1 size: " << mstack1.size() << std::endl;
		std::cout << "MutantStack2 size: " << mstack2.size() << std::endl;
		std::cout << std::endl;
		
		std::cout << "- Popping elements from MutantStack1 shouldn't affect MutantStack2" << std::endl;
		mstack1.pop();
		std::cout << "MutantStack1 size: " << mstack1.size() << std::endl;
		std::cout << "MutantStack2 size: " << mstack2.size() << std::endl;
	}
	
	return 0;
}
