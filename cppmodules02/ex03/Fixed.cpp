/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:57:12 by dario             #+#    #+#             */
/*   Updated: 2025/09/04 17:27:04 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fValue = copy._fValue;
}

Fixed::Fixed(const int nbr)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fValue = nbr << this->_fractionalBits;
}

Fixed::Fixed(const float nbr)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fValue = roundf(nbr * (1 << this->_fractionalBits));
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fValue = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

bool	Fixed::operator>(const Fixed &other)
{
	return (this->_fValue > other._fValue);
}

bool	Fixed::operator<(const Fixed &other)
{
	return (this->_fValue < other._fValue);
}

bool	Fixed::operator>=(const Fixed &other)
{
	return (this->_fValue >= other._fValue);
}

bool	Fixed::operator<=(const Fixed &other)
{
	return (this->_fValue <= other._fValue);
}

bool	Fixed::operator==(const Fixed &other)
{
	return (this->_fValue == other._fValue);
}

bool	Fixed::operator!=(const Fixed &other)
{
	return (this->_fValue != other._fValue);
}

Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed	ret;

	ret.setRawBits(this->_fValue + other._fValue);
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed	ret;

	ret.setRawBits(this->_fValue - other._fValue);
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed	ret;

	ret.setRawBits((this->_fValue * other._fValue) >> this->_fractionalBits);
	return (ret);
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed	ret;

	ret.setRawBits((this->_fValue << this->_fractionalBits) / other._fValue);
	return (ret);
}

Fixed	&Fixed::operator ++ (void)
{
	++this->_fValue;
	return (*this);
}

Fixed	&Fixed::operator -- (void)
{
	--this->_fValue;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	ret;

	ret.setRawBits(this->_fValue++);
	return (ret);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	ret;

	ret.setRawBits(this->_fValue--);
	return (ret);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return (first);
	return (second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first._fValue < second._fValue)
		return (first);
	return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first);
	return (second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first._fValue > second._fValue)
		return (first);
	return (second);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fValue;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	
	this->_fValue = raw;
}

int Fixed::toInt(void) const
{
	return (this->_fValue >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fValue / (1 << this->_fractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}
