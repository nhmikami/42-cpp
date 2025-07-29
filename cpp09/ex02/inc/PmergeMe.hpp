/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:24:24 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/29 19:05:59 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <set>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		~PmergeMe(void);
		
		PmergeMe&	operator=(const PmergeMe& other);
		
		void	processInput(int ac, char **av);
		void	sortVector(void);
		void	sortDeque(void);
};

int	jacobsthal(int num);

template <typename Container>
void	printContainer(const Container& c) {
	typename Container::const_iterator	it = c.begin();

	while (it != c.end()) {
		std::cout << " " << *it ;
		++it;
	}
	std::cout << std::endl; 
}

template <typename Container>
Container	generateInsertionSeq(size_t n) {
	Container	seq;
	
	int	jacobIndex = 2;
	int	next = jacobsthal(jacobIndex++);
	seq.push_back(next);

	while (seq.size() < n) {
		next = jacobsthal(jacobIndex++);

		if (next > static_cast<int>(n))
			next = static_cast<int>(n);
			
		while (std::find(seq.begin(), seq.end(), next) == seq.end()) {
			seq.push_back(next);
			next--;
		}
	}
	return seq;
}

template <typename Container>
void	binaryInsert(Container& sorted, Container& pend) {
	Container	insertionSeq = generateInsertionSeq<Container>(pend.size());

	for (size_t i = 1; i < insertionSeq.size(); i++) {
		int	elem = pend[insertionSeq[i] - 1];
		int	left = 0;
		int	right = insertionSeq[i] - 1 + i;

		while (left < right) {
			int	middle = (left + right) / 2;
			if (elem > sorted[middle])
				left = middle + 1;
			else
				right = middle;
		}
		sorted.insert(sorted.begin() + left, elem);
	}
}

template <typename Container, typename PairContainer>
Container	insertMergeSort(Container& input) {
	if (input.size() <= 1)
		return input;

	int	oddOut = -1;
	if (input.size() % 2 == 1) {
		oddOut = input.back();
		input.pop_back();
	}
	
	PairContainer	pairs;
	for (size_t i = 0; i < input.size(); i += 2) {
		int	a = input[i];
		int	b = input[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	
	Container	smaller;
	Container	larger;
	for (size_t i = 0; i < pairs.size(); i++) {
		smaller.push_back(pairs[i].first);
		larger.push_back(pairs[i].second);
	}
	if (oddOut != -1)
		smaller.push_back(oddOut);

	Container	sorted = insertMergeSort<Container, PairContainer>(larger);
	binaryInsert(sorted, smaller);
	return sorted;	
}


#endif
