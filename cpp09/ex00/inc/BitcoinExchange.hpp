/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/26 23:34:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

class BitcoinExchange {
	private:
		std::map<std::string, float>	_data;
		
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange(void);
		
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	loadData(const std::string& filename);
		void	processData(const std::string& filename) const;
		double	getExchangeRate(const std::string& date) const;

		void printData(void) const;
};

#endif
