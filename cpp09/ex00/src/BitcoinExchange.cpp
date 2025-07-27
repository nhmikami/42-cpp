/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:35:30 by marvin            #+#    #+#             */
/*   Updated: 2025/07/26 19:35:30 by marvin           ###   ########.fr       */
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
	if (!file.is_open()) {
		throw std::runtime_error("could not open file " + filename);
	}

	std::string	line;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("invalid header in file " + filename);
	}

	while (std::getline(file, line)) {
		std::istringstream	iss(line);
		std::string			date;
		float				value;

		std::getline(iss, date, ',');
		iss >> value;
		if (date.empty() || iss.fail() || value < 0) {
			throw std::runtime_error("invalid data in file " + filename);
		}

		_data[date] = value;
	}
	file.close();

	if (_data.empty()) {
		throw std::runtime_error(filename + "has no data");
	}
}

void	BitcoinExchange::processData(const std::string& filename) const {
	std::ifstream	file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("could not open file " + filename);
	}

	std::string	line;
	std::getline(file, line);
	if (line != "date | value") {
		throw std::runtime_error("invalid header in file " + filename);
	}

	while (std::getline(file, line)) {
		if (line.empty())
			continue ;

		std::istringstream	iss(line);
		std::string			date;
		float				value;

		std::getline(iss, date, " | ");
		iss >> value;

		if (!isValidDate(date)) {
			std::cout << "Error: invalid date ==> " << date << std::endl;
			continue;
		}
		if (value < 0) {
			std::cout << "Error: not a positive number ==> " << value << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number ==> " << value << std::endl;
			continue;
		}
		

		double rate = getExchangeRate(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	file.close();
}

double	BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);

	if (it != _data.end() && it->first == date)
		return it->second;

	if (it == _data.begin())
		return -1.0;

	--it; // anterior mais próxima
	return it->second;
}




bool	isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool	isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::istringstream iss(date);
	int		y, m, d;
	char	dash;

	if (!(iss >> y >> dash >> m >> dash >> d))
		return false;
	if (m < 1 || m > 12 || d < 1 || d > 31)
		return false;
	if ((m ==4 || m == 6 || m == 9 || m == 11) && d > 30)
		return false;
	if (m == 2 && isLeapYear(y) && d > 29)
		return false;
	if (m == 2 && !isLeapYear(y) && d > 28)
		return false;
	
	return true;
}

std::string	trim(const std::string& str) {
	size_t	start = str.find_first_not_of(" \t\n\r");
	size_t	end = str.find_last_not_of(" \t\n\r");
	if (start == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}


void BitcoinExchange::printData(void) const {
	for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); it++) {
		std::cout << it->first << " => " << std::setprecision(10) << it->second << std::endl;
	}
}
