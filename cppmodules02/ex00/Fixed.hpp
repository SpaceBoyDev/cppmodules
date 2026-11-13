/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:57:15 by dario             #+#    #+#             */
/*   Updated: 2025/09/03 17:39:42 by dario            ###   ########.fr       */
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
	Fixed	&operator = (const Fixed &copy);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private:
	int					_fValue;
	static const int	_fractionalBits = 8;
};

#endif