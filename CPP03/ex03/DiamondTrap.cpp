/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/07/25 14:44:45 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


// Constructor

DiamondTrap::DiamondTrap(std::string name) 
	:	ClapTrap(name + "_clap_name"), 
		ScavTrap(name), 
		FragTrap(name), 
		_name(name) 
{
    std::cout << "DiamondTrap " << this->_name << " is hunting!" << std::endl;

    setHitPoints(FragTrap::getHitPoints());
    setEnergyPoints(ScavTrap::getEnergyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
}

// Destructor
DiamondTrap::~DiamondTrap() 
{
	std::cout << "DiamondTrap " << this->_name << " is killed!" << std::endl;
}

// Member function specific to DiamondTrap
void DiamondTrap::whoAmI() 
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->_name << std::endl;
}
