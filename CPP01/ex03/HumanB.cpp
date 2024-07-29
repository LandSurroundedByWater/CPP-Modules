/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:38:47 by timo              #+#    #+#             */
/*   Updated: 2024/07/26 11:49:43 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
	return;
}

HumanB::HumanB(const HumanB &other) : _name(other._name), _weapon(other.weapon)
{}

HumanB& HumanB::operator=(const HumanB &other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }
    _name = other._name;
    _weapon = other._weapon; // This assignment might not be valid if Weapon is not copy-assignable
    return *this;
}

HumanB::~HumanB()
{
	return;
}

void HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
