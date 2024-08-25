/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:17:00 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/22 15:14:55 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"



Fixed sizeOfArea(const Fixed& x1, const Fixed& y1, const Fixed& x2, const Fixed& y2, const Fixed& x3, const Fixed& y3)
{
	Fixed res=(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)).abs() / 2;
	return res;
}



bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	
	Fixed triangleArea = sizeOfArea(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());

	Fixed pointTriangleA = sizeOfArea(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY()).abs();
	Fixed pointTriangleB = sizeOfArea(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY()).abs();
	Fixed pointTriangleC = sizeOfArea(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY()).abs();


	return (triangleArea == pointTriangleA + pointTriangleB + pointTriangleC);
}
