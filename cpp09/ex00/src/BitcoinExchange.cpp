/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:54:58 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/28 17:54:58 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void) {
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

void	BitcoinExchange::loadData(const std::string& filename) {
	std::ifstream	file(filename.c_str());
	checkFile(file, filename, "date,exchange_rate");

	std::string	line;
	while (std::getline(file, line)) {
		if (trim(line).empty())
			continue ;

		if (!checkLine(line, ","))
			throw std::runtime_error("invalid data in file " + filename);

		size_t	pos = line.find(",");
		std::string	date = trim(line.substr(0, pos));
		std::string	value = trim(line.substr(pos + 1));
		float		rate = std::atof(value.c_str());

		if (rate < 0)
			throw std::runtime_error("invalid data in file " + filename);

		_data[date] = rate;
	}
	file.close();

	if (_data.empty())
		throw std::runtime_error(filename + " has no data");
}

void	BitcoinExchange::processData(const std::string& filename) const {
	std::ifstream	file(filename.c_str());
	checkFile(file, filename, "date | value");

	std::string	line;
	while (std::getline(file, line)) {
		if (trim(line).empty()) {
			std::cout << "Error: empty line" << std::endl;
			continue ;
		}

		if (!checkLine(line, " | ")) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}

		size_t	pos = line.find(" | ");
		std::string	date = trim(line.substr(0, pos));
		std::string	value = trim(line.substr(pos + 3));
		float		amount = std::atof(value.c_str());

		if (amount < 0) {
			std::cout << "Error: not a positive number => " << amount << std::endl;
			continue;
		}
		else if (amount > 1000) {
			std::cout << "Error: too large a number => " << amount << std::endl;
			continue;
		}
		
		double rate = _getExchangeRate(date);
		if (rate < 0) {
			std::cout << "Error: no data available => " << date << std::endl;
			continue;
		}
		std::cout << date << " => " << amount << " = "
				  << std::fixed << std::setprecision(2) << amount * rate << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
	file.close();
}

double	BitcoinExchange::_getExchangeRate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);

	if (it != _data.end() && it->first == date)
		return it->second;
	else if (it == _data.begin())
		return -1.0;
	--it;
	return it->second;
}
