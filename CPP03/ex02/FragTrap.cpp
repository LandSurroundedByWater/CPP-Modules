/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/09/06 10:33:30 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	
	std::cout << "FragTrap " << this->_name << " is alive and hunting!" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap (const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->_name << " is copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap " << this->_name << " copy assignment operator used" << std::endl;
	}
	return *this;
} 

// Destructor
FragTrap::~FragTrap() 
{
	std::cout << "FragTrap " << this->_name << " is killed!" << std::endl;
}

//override attack function in ClapTrap
void FragTrap::attack(const std::string& target) 
{
		if (this->_energyPoints < 1) 
		{
			std::cout << "FragTrap " << this->_name << " has no energy points left!" << std::endl;
			return;
		}
		else if (this->_hitPoints < 1) 
		{
			std::cout << "FragTrap " << this->_name << " has no hit points left!" << std::endl;
			return;
		}
		else 
		{
			std::cout << "FragTrap " << this->_name << " attacks " << target << " with massive energy causing " << this->_attackDamage << " points of damage!" << std::endl;
			this->_energyPoints -= 1;
		}
}

// Member function specific to FragTrap
void FragTrap::highFivesGuys(void) 
{
	if (this->_energyPoints < 1) 
	{
		std::cout << "FragTrap " << this->_name << " has no energy points left!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " smiles and high fives everyone!" << std::endl;
}
