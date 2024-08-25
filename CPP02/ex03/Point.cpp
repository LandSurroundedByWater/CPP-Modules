/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:16:37 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/22 15:19:24 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point () : _x(0), _y(0) 
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::~Point()
{
//	std::cout << "Destructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const int x, const int y) : _x(x), _y(y) {}

Point::Point(const float x, const int y) : _x(x), _y(y) {}

Point::Point(const int x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& orig) {*this = orig;}

Point& Point::operator=(const Point& other) 
{
	if (this != &other)
	{
		//Fixed members are const, no modification
	}
	return *this;
}

Point Point::getPoint(void) const
{
	return *this;
}

Fixed Point::getX(void) const
{
	return this->_x;
}

Fixed Point::getY(void) const
{
	return this->_y;
}




