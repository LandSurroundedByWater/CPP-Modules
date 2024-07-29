/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:35:02 by timo              #+#    #+#             */
/*   Updated: 2024/07/26 11:16:55 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA() {}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)	
{
}

HumanA::HumanA(const HumanA &other) : _name(other._name), _weapon(other._weapon) 
{
}

HumanA& HumanA::operator=(const HumanA &other) {
    if (this == &other) {
        return *this;
    }
    _name = other._name;
    _weapon = other._weapon;
    return *this;
}

HumanA::~HumanA()
{
}

void HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
