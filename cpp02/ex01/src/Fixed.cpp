/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:10:11 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:10:11 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other) : _rawBits(other.getRawBits()){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_rawBits = other.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits(void) const {
	return _rawBits;
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _rawBits >> _fractionalBits;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
