/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:24:41 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/29 09:24:41 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe::~PmergeMe(void) {
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

void	PmergeMe::processInput(int ac, char **av) {
	std::set<int>	numbers;

	for (int i = 1; i < ac; i++) {
		std::string	input = av[i];
		std::istringstream	iss(input);
		int	value;

		iss >> value;
		if (iss.fail() || !iss.eof() || value <= 0)
			throw std::invalid_argument("invalid input: " + input);
		if (numbers.count(value) == 1)
			throw std::invalid_argument("duplicated input: " + input);
			
		numbers.insert(value);
		_vec.push_back(value);
		_deq.push_back(value);
	}
}

void	PmergeMe::sortVector(void) {
	std::cout << "Before:";
	printContainer(_vec);

	std::clock_t		start = clock();
	std::vector<int>	sorted = insertMergeSort<std::vector<int> >(_vec);
	std::clock_t		finish = clock();
	
	if (!isSorted<std::vector<int> >(sorted))
		throw std::runtime_error("sorting vector failed");
	
	std::cout << "After: ";
	printContainer(sorted);

	double	elapsedTime = static_cast<double>(finish - start) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : "
			  << std::fixed << std::setprecision(5) << elapsedTime << " ms" << std::endl;
}

void	PmergeMe::sortDeque(void) {
	std::clock_t	start = clock();
	std::deque<int>	sorted = insertMergeSort<std::deque<int> >(_deq);
	std::clock_t	finish = clock();
	
	if (!isSorted<std::deque<int> >(sorted))
		throw std::runtime_error("sorting deque failed");

	double	elapsedTime = static_cast<double>(finish - start) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : "
			  << std::fixed << std::setprecision(5) << elapsedTime << " ms" << std::endl;
}

int	jacobsthal(int num) {
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	return jacobsthal(num - 1) + 2 * jacobsthal(num - 2);
}
