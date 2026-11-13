/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:35:17 by dario             #+#    #+#             */
/*   Updated: 2025/09/04 18:21:22 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

// float sign(Point const &p1, Point const &p2, Point const &p3)
// {
//     return (p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) -
//            (p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat());
// }

Fixed	sign(Point const &p1, Point const &p2, Point const &p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
           (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1 = sign(point, a, b);
	Fixed	d2 = sign(point, b, c);
	Fixed	d3 = sign(point, c, a);

	bool	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return ((has_neg && has_pos) == false && d1 != 0 && d2 != 0 && d3 != 0);
}
