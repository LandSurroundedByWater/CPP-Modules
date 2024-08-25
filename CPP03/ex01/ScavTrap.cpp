/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/08/25 15:23:12 by tsaari           ###   ########.fr       */
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

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	// Copy initialization code
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this == &other) {
		return *this; // Handle self-assignment
	}
	ClapTrap::operator=(other);
	return *this;
}
// Destructor
ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap " << this->_name << " is terminated" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() < 1)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy!" << std::endl;
		return;
	}
	
	else if (this->getHitPoints() < 1)
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
