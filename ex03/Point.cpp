/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:27:04 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/09 14:31:28 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	// std::cout << "Point created" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "Point created" << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	// std::cout << "Point created" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point destroyed" << std::endl;
}

Point&  Point::operator=(const Point &f)
{
	if (this != &f)
	{
		(Fixed) this->_x = f.getX();
		(Fixed) this->_y = f.getY();
	}
	return (*this);
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}
