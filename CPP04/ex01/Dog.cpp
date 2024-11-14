/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:10:07 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:10:09 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog created" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain); 
		std::cout << "Dog assignment operator called" << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog deleted" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Hau! Woof! Guau!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}

