/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:02:11 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/28 18:06:55 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	checkFile(std::ifstream& file, const std::string& filename, const std::string& header) {
	if (!file.is_open())
		throw std::runtime_error("could not open file " + filename);

	std::string	line;
	std::getline(file, line);
	if (trim(line) != header)
		throw std::runtime_error("invalid header in file " + filename);
}

bool	checkLine(const std::string& line, const std::string& sep) {
	size_t	pos = line.find(sep);
	if (pos == std::string::npos)
		return false;

	std::string	date = trim(line.substr(0, pos));
	if (date.empty() || !isValidDate(date))
		return false;

	std::string	value = trim(line.substr(pos + sep.length()));
	if (value.empty() || !isValidValue(value))
		return false;

	return true;
}

static bool	isLeapYear(int year) {
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

bool	isValidValue(const std::string& value) {
	std::istringstream	iss(value);
	double num;

	iss >> num;
	if (iss.fail() || !iss.eof())
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
