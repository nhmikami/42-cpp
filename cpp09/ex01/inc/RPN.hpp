/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:24:24 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/30 21:26:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <stack>

class RPN {
	private:
		std::stack<int>	_operands;

		bool	_isValidDigit(const std::string& token);
		bool	_isValidOperator(const std::string& token);
		void	_pushToken(const std::string& token);
		
	public:
		RPN(void);
		RPN(const RPN& other);
		~RPN(void);
		
		RPN&	operator=(const RPN& other);
		
		int		solveRPN(const std::string& expression);
};

#endif
