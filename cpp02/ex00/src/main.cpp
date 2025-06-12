#include "Fixed.hpp"

int	main(void) {
	std::cout << "* Default constructor" << std::endl;
	Fixed	a;
	std::cout << std::endl;

	std::cout << "* Copy constructor" << std::endl;
	Fixed	b(a);
	std::cout << std::endl;

	std::cout << "* Default constructor + Assignment operator" << std::endl;
	Fixed	c;
	c = b;
	std::cout << std::endl;

	std::cout << "* getRawBits" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "* setRawBits" << std::endl;
	a.setRawBits(42);
	b.setRawBits(21);
	c.setRawBits(84);
	std::cout << std::endl;

	std::cout << "* getRawBits" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	return 0;
}