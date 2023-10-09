/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:38:19 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/09 14:03:24 by dpalmer          ###   ########.fr       */
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
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
