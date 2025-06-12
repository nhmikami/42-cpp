#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		// Constructors and Destructor
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();

		// Assignment operator
		Fixed&	operator=(const Fixed& other);
		
		// Comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// Arithmetic operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		// Increment / Decrement
		Fixed&	operator++();         // Pre-increment
		Fixed&	operator--();         // Pre-decrement
		Fixed	operator++(int);      // Post-increment
		Fixed	operator--(int);      // Post-decrement

		// Min / Max static functions
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		// Getters and Setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Conversion functions
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif
