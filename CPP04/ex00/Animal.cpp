/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:08:00 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:08:03 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ----------------------Constructors-----------------

Animal::Animal()
{
	_type = "Nontype animal";
	std::cout << "Animal nonparametric default constructor used" <<std::endl; 
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type of " << _type << " parametric constructor used" <<std::endl; 
}

Animal::Animal (const Animal& other) : _type(other._type) 
{
		std::cout << "Animal type of " << _type << " copy constructor used" <<std::endl; 

}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
	{
		this->setType(other._type);
			std::cout << "Animal type of " << _type << " copy assign operator used" <<std::endl; 
	}
	return *this;
} 

// ----------------------Destructor-----------------

Animal::~Animal() 
{
		std::cout << "Animal type of " << _type << " destructor used" <<std::endl; 
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
