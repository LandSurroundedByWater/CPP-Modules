/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:08:24 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:08:27 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	std::cout << "Cat type of " << this->getType() << " nonparametric construtor used" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) 
{
	std::cout << "Cat type of " << this->getType() << " copy constructor used" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Cat type of " << this->getType() << " copy assign opperator used" << std::endl;
	}
	return *this;
}

Cat::~Cat() 
{
	std::cout << "Cat type of " << this->getType() << " desructor used" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau! Miau! Meow!" << std::endl;
}

