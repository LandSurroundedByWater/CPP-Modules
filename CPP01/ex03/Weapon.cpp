/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:25:31 by timo              #+#    #+#             */
/*   Updated: 2024/07/26 11:55:08 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
    this->_type = type;
}

Weapon::Weapon(const Weapon& other) : _type(other._type)
{}

Weapon& Weapon::operator=(const Weapon &other) {
    if (this == &other) {
        return *this;
    }
    _type = other._type;
    return *this;
}

Weapon::~Weapon()
{
    return;
}

std::string Weapon::getType(void) const
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}