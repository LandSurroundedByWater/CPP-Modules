/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:56:32 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/23 11:16:46 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int n)
{
	this->value = n << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
	this->value = static_cast<int>(roundf(n * (1 << fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& orig)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = orig;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
		this->value = other.getRawBits(); 
	return *this;
}


bool Fixed::operator>(const Fixed& other) const 
{
		std::cout << "Bool bigger than function called" << std::endl;
		return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const 
{
		std::cout << "Bool smaller than function called" << std::endl;
		return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const 
{
		std::cout << "Bool bigger or equal than function called" << std::endl;
		return this->value >= other.value;
}
bool Fixed::operator<=(const Fixed& other) const 
{
		std::cout << "Bool smaller or equal  than function called" << std::endl;
		return this->value >= other.value;
}

bool Fixed::operator==(const Fixed& other) const 
{
		std::cout << "Bool equal than function called" << std::endl;
		return this->value == other.value;
}
bool Fixed::operator!=(const Fixed& other) const 
{
		std::cout << "Bool not equal than function called" << std::endl;
		return this->value != other.value;
}

int Fixed::operator+

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return(float(this->value) / (1 << fractionalBits));
}

int Fixed::toInt( void ) const
{
	return(this->value >> fractionalBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}


std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}