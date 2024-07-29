/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/07/25 14:40:56 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)   : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(2)
{
	std::cout << "ClapTrap " << this->_name << " is created" << std::endl;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
		return;
	}
	
	else if (this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints - amount < 1)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount - this->_hitPoints << " points of damage!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
	}
}	

int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}
int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}
int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}	