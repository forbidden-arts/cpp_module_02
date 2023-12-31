/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:27:01 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/09 14:31:51 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	~Point();

	Point&	operator=(const Point &f);

	Fixed	getX(void) const ;
	Fixed	getY(void) const ;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
