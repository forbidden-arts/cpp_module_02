/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:17:00 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/09 13:30:06 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
