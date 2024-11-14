/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/09/06 10:54:58 by tsaari           ###   ########.fr       */
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
	_guardMode = false;
}

ScavTrap::ScavTrap (const ScavTrap& other) : ClapTrap(other), _guardMode(other._guardMode)
{
	std::cout << "ScavTrap " << this->_name << " is copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_guardMode = other._guardMode;
		std::cout << "ScavTrap " << this->_name << " copy assignment operator used" << std::endl;
	}
	return *this;
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
			std::cout << "ScavTrap " << this->_name << " has no energy points left!" << std::endl;
			return;
		}
		else if (this->_hitPoints < 1) 
		{
			std::cout << "ScavTrap " << this->_name << " has no hit points left!" << std::endl;
			return;
		}
		else 
		{
			std::cout << "ScavTrap " << this->_name << " attacksssss " << target << " dealing " << this->_attackDamage << " points of damage!" << std::endl;
			this->_energyPoints -= 1;
		}
}

void ScavTrap::guardGate() 
{
	if (_guardMode)
	{
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate!" << std::endl;
		_guardMode = true;
	}
}
