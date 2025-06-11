#include "Sed.hpp"

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string	filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << "Error: The first string (s1) cannot be empty." << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 1;
	}
	std::string content = getContent(infile);
	infile.close();

	std::string new_content = replaceStrings(content, s1, s2);
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create output file." << std::endl;
		return 1;
	}
	outfile << new_content;
	outfile.close();

	return 0;
}
