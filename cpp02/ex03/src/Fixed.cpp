/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:12:01 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:12:01 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* *********************** Constructors and Destructor ********************** */
Fixed::Fixed() : _rawBits(0) {
}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) {
}

Fixed::Fixed(const float value) 
	: _rawBits(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
}

Fixed::Fixed(const Fixed& other) : _rawBits(other.getRawBits()) {
}

Fixed::~Fixed() {
}

/* *************************** Assignment operator ************************** */
Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		_rawBits = other.getRawBits();
	}
	return *this;
}

/* ************************** Comparison operators ************************** */
bool	Fixed::operator>(const Fixed& other) const {
	return _rawBits > other.getRawBits();
}

bool	Fixed::operator<(const Fixed& other) const {
	return _rawBits < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed& other) const {
	return _rawBits >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed& other) const {
	return _rawBits <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed& other) const {
	return _rawBits == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed& other) const {
	return _rawBits != other.getRawBits();
}

/* ************************** Arithmetic operators ************************** */
Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	result;
	result.setRawBits(this->_rawBits + other.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed	result;
	result.setRawBits(this->_rawBits - other.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	result;
	result.setRawBits((this->_rawBits * other.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const {
	if (other.getRawBits() == 0) {
		if (this->_rawBits > 0)
			return (Fixed(INFINITY));
		else if (this->_rawBits < 0)
			return (Fixed(-INFINITY));
		else
			return (Fixed(0));
	}
	Fixed	result;
	result.setRawBits((this->_rawBits << _fractionalBits) / other.getRawBits());
	return result;
}

/* ************************** Increment / Decrement ************************* */
Fixed&	Fixed::operator++() {
	_rawBits++;
	return *this;
}

Fixed&	Fixed::operator--() {
	_rawBits--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	_rawBits++;
	return temp;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	_rawBits--;
	return temp;
}

/* *********************** Min / Max static functions *********************** */
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

/* *************************** Getters and Setters ************************** */
int	Fixed::getRawBits(void) const {
	return _rawBits;
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

/* ************************** Conversion functions ************************** */
float	Fixed::toFloat(void) const {
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _rawBits >> _fractionalBits;
}

/* ***************************** Output operator **************************** */
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
