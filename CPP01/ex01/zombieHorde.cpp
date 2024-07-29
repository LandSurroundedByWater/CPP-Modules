/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:36:26 by timo              #+#    #+#             */
/*   Updated: 2024/07/19 12:08:03 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"


Zombie* zombieHorde(int N, const std::string &name)
{
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i) 
	{
		horde[i].setZombieName(name);
	}
	return horde;
}

void deleteHorde(Zombie* horde) 
{
	delete[] horde; 
}
