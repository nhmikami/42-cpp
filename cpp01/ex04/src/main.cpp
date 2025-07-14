/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:07:26 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:07:26 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << YELLOW << "Usage: " << RESET << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string	filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << RED << "Error: " << RESET << "The first string (s1) cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << RED << "Error: " << RESET << "Could not open file " << filename << std::endl;
		return 1;
	}
	std::string content = getContent(infile);
	infile.close();

	std::string new_content = replaceStrings(content, s1, s2);
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << RED << "Error: " << RESET << "Could not create output file" << std::endl;
		return 1;
	}
	outfile << new_content;
	outfile.close();

	return 0;
}
