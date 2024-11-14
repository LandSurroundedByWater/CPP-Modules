/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:09:16 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:09:18 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat") 
{
	std::cout << "WrongCat nonparametric default constructor used" <<std::endl; 
}


WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
	std::cout << "WrongCat type of " << this->getType() << " copy constructor used" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		std::cout << "WrongCat type of " << this->getType() << " copy assign opperator used" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat type of " << this->getType() << " desructor used" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat awful sound" << std::endl;
}

