/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:11:56 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:11:56 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	calcArea(Point const a, Point const b, Point const c) {
	Fixed	area = (a.getX() * (b.getY() - c.getY()) +
					b.getX() * (c.getY() - a.getY()) +
					c.getX() * (a.getY() - b.getY())) / Fixed(2);
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	areaABC = calcArea(a, b, c);
	Fixed	areaPAB = calcArea(point, a, b);
	Fixed	areaPBC = calcArea(point, b, c);
	Fixed	areaPCA = calcArea(point, c, a);

	if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
		return false;
	
	return (areaABC == areaPAB + areaPBC + areaPCA);
}
