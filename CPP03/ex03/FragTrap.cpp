/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/07/26 09:45:03 by tsaari           ###   ########.fr       */
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
