#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

std::string	getContent(std::ifstream& infile);
std::string	replaceStrings(std::string content, std::string s1, std::string s2);

#endif