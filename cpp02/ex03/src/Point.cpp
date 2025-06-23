/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:12:53 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:12:53 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {
}

Point::~Point() {
}

Point& Point::operator=(const Point& other) {
	(void)other;
	return *this;
}

Fixed	Point::getX(void) const {
	return _x;
}

Fixed	Point::getY(void) const {
	return _y;
}
