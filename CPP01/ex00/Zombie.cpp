/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:25 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/19 10:16:34 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : _name(name) {
    std::cout << "Zombie " << this->_name << " is created." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->_name << " is destroyed." << std::endl;
}

void Zombie::announce(void) const {
    std::cout << this->_name << " says: Braiiiiiiinnnssss..." << std::endl;
}
