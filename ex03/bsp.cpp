/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:33:26 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/09 14:37:48 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed x) {
	if (x < 0)
		return (x * -1);
	return (x);
}

static Fixed	area(Point const a, Point const b, Point const c)
{
	return ((
			a.getX() * (b.getY() - c.getY()) +
			b.getX() * (c.getY() - a.getY()) +
			c.getX() * (a.getY() - b.getY())
			) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abcArea = abs(area(a, b, c));
	Fixed	pointAB = abs(area(point, a, b));
	Fixed	pointBC = abs(area(point, b, c));
	Fixed	pointCA = abs(area(point, c, a));

	return	(abcArea == pointAB + pointBC + pointCA);
}
