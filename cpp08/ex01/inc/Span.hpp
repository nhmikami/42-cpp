/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/23 18:43:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

class Span {
	private:
		Span(void);
		
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		~Span(void);
		
		Span&	operator=(const Span& other);

		void	addNumber(int number);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end) {
			if (std::distance(begin, end) + _numbers.size() > _maxSize)
				throw std::length_error("Span is full: cannot add more numbers");
			_numbers.insert(_numbers.end(), begin, end);
		}
};

#endif
