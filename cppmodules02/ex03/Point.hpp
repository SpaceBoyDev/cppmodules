/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:26 by dario             #+#    #+#             */
/*   Updated: 2025/09/04 18:19:59 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &copy);
	Point	&operator = (const Point &copy);
	~Point();

	Fixed	getX() const;
	Fixed	getY() const;
	
	private:
	const Fixed	_x;
	const Fixed	_y;
	// Puedo poner mas variables si quiero
};

#endif