/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:36:26 by timo              #+#    #+#             */
/*   Updated: 2024/08/11 13:46:48 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int hordeSize, const std::string &name)
{
	Zombie* horde = new Zombie[hordeSize];
	for (int i = 0; i < hordeSize; ++i) 
	{
		horde[i].setZombieName(name);
	}
	return horde;
}

void deleteHorde(Zombie* horde) 
{
	delete[] horde; 
}
