/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:09:53 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:09:55 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	std::cout << "Cat created" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete(_brain);
		this->_brain = new Brain(*other._brain);
		std::cout << "Cat assignment operator used" << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	delete(_brain);
	std::cout << "Cat deleted" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau! Miau! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}

