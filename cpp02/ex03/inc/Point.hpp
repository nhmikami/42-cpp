/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:11:49 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:11:49 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& other);
		~Point(void);

		Point&	operator=(const Point& other);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
