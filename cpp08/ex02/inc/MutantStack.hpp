/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/23 19:08:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack& other);
		~MutantStack(void);
		
		MutantStack&	operator=(const MutantStack& other);

		typedef typename std::stack<T, Container>::container_type::iterator	iterator;
		iterator		begin(void);
		iterator		end(void);

		typedef typename std::stack<T, Container>::container_type::const_iterator	const_iterator;
		const_iterator	begin(void) const;
		const_iterator	end(void) const;
		
		typedef typename std::stack<T, Container>::container_type::reverse_iterator	reverse_iterator;
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);

		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;
		const_reverse_iterator	rbegin(void) const;
		const_reverse_iterator	rend(void) const;
		
};

#include "MutantStack.tpp"

#endif
