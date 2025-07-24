/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:49:34 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/23 17:49:34 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) {
}

Span::Span(unsigned int N) : _maxSize(N) {
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

Span::~Span(void) {
}

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

unsigned int	Span::size(void) const {
	return _numbers.size();
}

void	Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw std::length_error("Span is full: cannot add more numbers");
	_numbers.push_back(number);
}

int	Span::shortestSpan(void) const {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int>	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int	minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); i++) {
		int	span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int	Span::longestSpan(void) const {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	int	min = *std::min_element(_numbers.begin(), _numbers.end());
	int	max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}
