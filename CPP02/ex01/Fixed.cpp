/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:56:32 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/24 09:30:55 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	this->_value = n << Fixed::_fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n )
{
	this->_value = roundf(n * (1 << Fixed::_fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& orig)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = orig;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
		this->_value = other.getRawBits(); 
	return *this;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat( void ) const
{
	return(float(this->_value) / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
	return(this->_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
	out << fixed.toFloat();
	return out;
}
