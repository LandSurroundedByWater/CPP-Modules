/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:16:32 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/22 15:22:11 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	
	public:
		
		Point();
		Point(float x, float y);
		Point(int x, int y);
		Point(float x, int y);
		Point(int x, float y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();
	
		Point getPoint(void) const;
		Fixed getX(void) const;
		Fixed getY(void) const;
	
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif