#include <cctype>
#include <iostream>

int main(int ac, char **av)
{
	std::string input;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int i = 1; i < ac; ++i)
	{
		input = av[i];
		for (size_t j = 0; j < input.length(); j++)
			std::cout << static_cast<char>(std::toupper(input[j]));
	}
	std::cout << std::endl;

	return 0;
}