/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/07/26 12:45:14 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "FragTrap " << this->_name << " is hunting!" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}
//Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {}

//Copy assign constructor
FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this == &other) {
		return *this;
	}
	ClapTrap::operator=(other);
	return *this;
}

// Destructor
FragTrap::~FragTrap() 
{
	std::cout << "FragTrap " << this->_name << " is killed!" << std::endl;
}


// Member function specific to FragTrap
void FragTrap::highFivesGuys(void) 
{
	std::cout << "FragTrap " << this->_name << " says High Five!" << std::endl;
}
