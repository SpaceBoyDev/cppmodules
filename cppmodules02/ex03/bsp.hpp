/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:07:29 by dario             #+#    #+#             */
/*   Updated: 2025/09/04 18:08:14 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
# define BSP_HPP

#include "Point.hpp"

Fixed	sign(Point const &p1, Point const &p2, Point const &p3);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif