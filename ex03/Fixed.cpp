/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:00:02 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/09 14:11:20 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPoint(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedPoint(n << _fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixedPoint(std::roundf(n * (1 << _fractionalBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed&	Fixed::operator=(const Fixed &f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->_fixedPoint = f.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPoint >> _fractionalBits);
}

std::ostream& operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

bool	Fixed::operator>(const Fixed &f) const
{
	return (this->getRawBits() > f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (this->getRawBits() < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (this->getRawBits() >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (this->getRawBits() <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (this->getRawBits() == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (this->getRawBits() != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &f) const
{
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	++this->_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	temp._fixedPoint = this->_fixedPoint++;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	--this->_fixedPoint;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	temp._fixedPoint = this->_fixedPoint--;
	return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
