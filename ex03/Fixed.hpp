/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:56:06 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/09 13:59:20 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;

public:
	Fixed();							//constructor
	Fixed(const Fixed &f);				//copy constructor
	Fixed& operator=(const Fixed &f);	//copy assignment constructor
	~Fixed();							//destructor
	Fixed(const int n);
	Fixed(const float n);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed &f) const;
	bool	operator<(const Fixed &f) const;
	bool	operator>=(const Fixed &f) const;
	bool	operator<=(const Fixed &f) const;
	bool	operator==(const Fixed &f) const;
	bool	operator!=(const Fixed &f) const;

	Fixed	operator+(const Fixed &f) const;
	Fixed	operator-(const Fixed &f) const;
	Fixed	operator*(const Fixed &f) const;
	Fixed	operator/(const Fixed &f) const;

	Fixed&	operator++(void); // prefix
	Fixed	operator++(int); // postfix
	Fixed&	operator--(void); // prefix
	Fixed	operator--(int); // postfix

	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
