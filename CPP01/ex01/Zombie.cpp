/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:25 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/19 12:02:42 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed Zombie") {
    std::cout << "Zombie " << this->_name << " is created." << std::endl;
}

Zombie::Zombie(const std::string &name) : _name(name) {
	std::cout << "Zombie " << this->_name << " is created." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " is destroyed." << std::endl;
}

void Zombie::setZombieName(std::string name)
{
	this->_name = name;
}

void Zombie::announce(void) const {
	std::cout << this->_name << " says: Braiiiiiiinnnssss..." << std::endl;
}
