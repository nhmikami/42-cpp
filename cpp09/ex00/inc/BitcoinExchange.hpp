/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:14 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/30 21:26:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float>	_data;

		double	_getExchangeRate(const std::string& date) const;
		
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange(void);
		
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	loadData(const std::string& filename);
		void	processData(const std::string& filename) const;
};

void		checkFile(std::ifstream& file, const std::string& filename, const std::string& header);
bool		checkLine(const std::string& line, const std::string& sep);
bool		isValidValue(const std::string& value);
bool		isValidDate(const std::string& date);
std::string	trim(const std::string& str);

#endif
