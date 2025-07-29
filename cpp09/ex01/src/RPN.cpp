/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:51:08 by marvin            #+#    #+#             */
/*   Updated: 2025/07/28 21:51:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN::~RPN(void) {
}

RPN&	RPN::operator=(const RPN& other) {
	if (this != &other) {
		_operands = other._operands;
	}
	return *this;
}

int	RPN::solveRPN(const std::string& expression) {
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token) {
		if (_isValidDigit(token))
			_pushToken(token);

		else if (_isValidOperator(token)) {
			if (_operands.size() < 2)
				throw std::runtime_error("invalid expression");

			int b = _operands.top();
			_operands.pop();
			int a = _operands.top();
			_operands.pop();

			switch (token[0]) {
				case '+':
					_operands.push(a + b);
					break;
				case '-':
					_operands.push(a - b);
					break;
				case '*':
					_operands.push(a * b);
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("division by zero");
					_operands.push(a / b);
					break;
			}
		}

		else
			throw std::runtime_error("invalid token");
	}

	if (_operands.size() != 1)
		throw std::runtime_error("invalid expression");

	return _operands.top();
}

bool	RPN::_isValidDigit(const std::string& token) {
	std::istringstream  iss(token);
	int num;

	iss >> num;
	if (iss.fail() || !iss.eof())
	  	return false;
	if (num < 0 || num > 9)
		return false;

	return true;
}

bool	RPN::_isValidOperator(const std::string& token) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void	RPN::_pushToken(const std::string& token) {
	std::istringstream  iss(token);
	int num;

	iss >> num;
	_operands.push(num);
	return ;
}
