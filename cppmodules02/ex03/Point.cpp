#include "Point.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:22 by dario             #+#    #+#             */
/*   Updated: 2025/09/04 17:14:24 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Point::Point(void) : _x(0), _y(0)
{

}

Point::Point(const float x, float y) :
	_x(x), _y(y)
{

}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {}

Point &Point::operator=(const Point &copy)
{
	if (this != &copy)
	{
		(Fixed)this->_x = copy._x;
		(Fixed)this->_y = copy._y;
	}
	return (*this);
}

Point::~Point()
{

}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}
