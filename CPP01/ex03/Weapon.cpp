/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:25:31 by timo              #+#    #+#             */
/*   Updated: 2024/08/11 14:12:03 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
	return;
}

const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}