/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:56:32 by tsaari            #+#    #+#             */
/*   Updated: 2024/10/14 13:41:25 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//-----------------Constructors and destructor------------------

Fixed::Fixed()
{
	this->_value = 0;
	//std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int n)
{
	this->_value = n << _fractionalBits;
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
	this->_value = static_cast<int>(roundf(n * (1 << _fractionalBits)));
	//std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& orig)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = orig;
}

Fixed::~Fixed() 
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
		this->_value = other.getRawBits(); 
	return *this;
}

//--------------------getters and setters-------------------------

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return(this->_value >> _fractionalBits);
}

//-----------------comparison------

bool Fixed::operator>(const Fixed& other) const 
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const 
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const 
{
	return this->getRawBits() >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed& other) const 
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const 
{
	return this->getRawBits() == other.getRawBits();
	
}
bool Fixed::operator!=(const Fixed& other) const 
{
	return this->getRawBits() != other.getRawBits();
}

///------------arithmetic-------------


Fixed Fixed::operator+(const Fixed& rhs) const 
{
	return Fixed(this->_value + rhs._value);
}

Fixed Fixed::operator-(const Fixed& rhs) const 
{
	return Fixed(this->_value - rhs._value);
}


Fixed Fixed::operator*(const Fixed& rhs) const 
{
	long long rawResult = static_cast<long long>(this->_value) * rhs._value;
	int adjustedResult = static_cast<int>(rawResult >> _fractionalBits);
	Fixed temp;
	temp._value = adjustedResult;
	return temp;
}
	

Fixed Fixed::operator/(const Fixed& rhs) const 
{
	int rawResult = this->_value / rhs._value;
	int adjustedResult = rawResult >> _fractionalBits;
	Fixed temp;
	temp._value = adjustedResult;
	return temp;
}


//-------------------increment/decrement--------------

Fixed& Fixed::operator++() 
{
	++this->_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_value;
	return temp;
}

Fixed& Fixed::operator--() 
{
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_value;
	return temp;
}

//-----------min and max --------------p

//modifiable functions
Fixed& Fixed::min(Fixed& first, Fixed& other)
{
	return (first.getRawBits() < other.getRawBits()) ? first : other;
}

Fixed& Fixed::max(Fixed& first, Fixed& other)
{
	return (first.getRawBits() > other.getRawBits()) ? first : other;
}
//read only functions
const Fixed& Fixed::min(const Fixed& first, const Fixed& other)
{
	return (first.getRawBits() < other.getRawBits()) ? first : other;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& other)
{
	return (first.getRawBits() > other.getRawBits()) ? first : other;
}

//------------overload stream insertion operator------------
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
	out << fixed.toFloat();
	return out;
}

