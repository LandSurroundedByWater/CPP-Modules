/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:38:47 by timo              #+#    #+#             */
/*   Updated: 2024/08/11 14:37:45 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr)
{
	std::cout << "HumanB " << this->_name << " is created with no weapon." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destroyed." << std::endl;
}

void HumanB::attack(void) const
{
	if (this->_weapon == nullptr)
	std::cout << this->_name << " has no weapon!" << std::endl;
	else
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	std::cout << this->_name << " got weapon " << this->_weapon->getType() << std::endl;
}


