/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:09:27 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:09:29 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ----------------------Constructors-----------------

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal " << _type << " created" <<std::endl; 
}

Animal::Animal (const Animal& other) : _type(other._type) 
{
	std::cout << "Animal " << _type << " copied" <<std::endl; 
}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
	{
		this->_type = (other._type);
		std::cout << "Animal " << _type << " assignment operator called" <<std::endl; 
	}
	return *this;
} 

// ----------------------Destructor-----------------

Animal::~Animal()
{
	std::cout << "Animal " << _type << " deleted" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}


//-------------Member functions------------------

void Animal::makeSound() const
{
	std::cout << "Some generic animal Sound" << std::endl;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}
