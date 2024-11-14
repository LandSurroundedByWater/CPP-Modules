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

//------------- Constructors ------------------


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

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) 
{
	std::cout << "DiamondTrap " << this->_name << " is copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) 
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
		std::cout << "DiamondTrap " << this->_name << " copy assignment operator used" << std::endl;
	}
	return *this;
}

// ----------Destructor------------------


DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " is buried undergroud!" << std::endl;
}

// -------------------Member function specific to DiamondTrap----------------

void DiamondTrap::attack(std::string enemy)
{
	ScavTrap::attack(enemy);
}


void DiamondTrap::whoAmI() 
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name<< std::endl;
}
