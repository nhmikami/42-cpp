/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:07:31 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:07:31 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

std::string	getContent(std::ifstream& infile) {
	std::string line;
	std::string content;

	while (std::getline(infile, line)) {
		content += line + "\n";
	}
	return content;
}

std::string	replaceStrings(std::string content, std::string s1, std::string s2) {
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}

	return content;
}
