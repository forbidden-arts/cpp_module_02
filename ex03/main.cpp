/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:13:38 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/10 10:04:02 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)) == true)
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
	return (0);
}
