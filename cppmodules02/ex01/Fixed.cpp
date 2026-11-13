/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:57:12 by dario             #+#    #+#             */
/*   Updated: 2025/09/03 17:39:42 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fValue = copy._fValue;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fValue = nbr << this->_fractionalBits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fValue = roundf(nbr * (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fValue >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fValue / (1 << this->_fractionalBits));
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fValue = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_fValue = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}
