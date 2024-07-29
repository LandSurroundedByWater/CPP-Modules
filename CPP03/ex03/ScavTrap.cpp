/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/07/25 12:31:23 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "ScavTrap " << this->_name << " is now working" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

// Destructor
ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap " << this->_name << " is terminated" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy!" << std::endl;
		return;
	}
	
	else if (this->_hitPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " has no hit points!" << std::endl;
		return;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " aggressively attacks " << target << ", inflicting " 
				  << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

// Member function specific to ScavTrap
void ScavTrap::guardGate() 
{
	std::cout << "ScavTrap " << this->_name << " is now guarding the gate!" << std::endl;
}
