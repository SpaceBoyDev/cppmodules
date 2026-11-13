/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:57:15 by dario             #+#    #+#             */
/*   Updated: 2025/09/03 17:58:17 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed	&operator = (const Fixed &copy);
	~Fixed();

	bool	operator > (const Fixed &other);
	bool	operator < (const Fixed &other);
	bool	operator >= (const Fixed &other);
	bool	operator <= (const Fixed &other);
	bool	operator == (const Fixed &other);
	bool	operator != (const Fixed &other);

	Fixed	operator + (const Fixed &other);
	Fixed	operator - (const Fixed &other);
	Fixed	operator * (const Fixed &other);
	Fixed	operator / (const Fixed &other);

	Fixed	&operator ++ (void);
	Fixed	&operator -- (void);
	Fixed	operator ++ (int);
	Fixed	operator -- (int);

	static 			Fixed	&min(Fixed &first, Fixed &second);
	static const	Fixed	&min(const Fixed &first, const Fixed &second);
	static 			Fixed	&max(Fixed &first, Fixed &second);
	static const	Fixed	&max(const Fixed &first, const Fixed &second);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;


	private:
	int					_fValue;
	static const int	_fractionalBits = 8;
};

std::ostream	&operator << (std::ostream& os, const Fixed& fixed);


#endif