/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:08:37 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:08:40 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	std::cout << "Dog type of " << this->getType() << " nonparametric constructor used" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
	std::cout << "Dog type of " << this->getType() << " copy constructor used" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Dog type of " << this->getType() << " copy assign opperator used" << std::endl;
	}
	return *this;
}

Dog::~Dog() 
{
	std::cout << "Dog type of " << this->getType() << " destructor used" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Hau! Woof! Guau-guau!" << std::endl;
}

