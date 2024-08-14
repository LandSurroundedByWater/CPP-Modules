/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:25 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/11 13:28:12 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : _name(name)
{
	std::cout << "Zombie " << this->_name << " is created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is destroyed." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
