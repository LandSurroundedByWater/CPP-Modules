/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:09:02 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:09:03 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// ----------------------Constructors-----------------

WrongAnimal::WrongAnimal() : _type("DefaultAnimal")
{
	std::cout << "WrongAnimal nonparametric default constructor used" <<std::endl; 
}


WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal type of " << _type << " parametric constructor used" <<std::endl; 
}

WrongAnimal::WrongAnimal (const WrongAnimal& other) : _type(other._type) 
{
		std::cout << "WrongAnimal type of " << _type << " copy constructor used" <<std::endl; 
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
	{
		this->setType(other._type);
			std::cout << "WrongAnimal type of " << _type << " copy assign operator used" <<std::endl; 
	}
	return *this;
} 

// ----------------------Destructor-----------------

WrongAnimal::~WrongAnimal() 
{
		std::cout << "WrongAnimal type of " << _type << " destructor used" <<std::endl; 
}

std::string WrongAnimal::getType() const
{
	return _type;
}


//-------------Member functions------------------

void WrongAnimal::makeSound() const
{
	std::cout << "Some odd WrongAnimal Sound!" << std::endl;
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}
