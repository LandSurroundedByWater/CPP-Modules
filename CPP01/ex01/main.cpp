/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:50:38 by timo              #+#    #+#             */
/*   Updated: 2024/08/11 13:44:18 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 8;
	{
		Zombie* horde = zombieHorde(N, "Walker");

		if (sizeof(horde) > 0) 
		{
			for (int i = 0; i < N; ++i)
			{
				horde[i].announce(); // Announce each Zombie
			}
			deleteHorde(horde); // Free the allocated memory
		}
	}
	{
		Zombie* horde = zombieHorde(N, "ShadowZombie");

		if (sizeof(horde) > 0) 
		{
			for (int i = 0; i < N; ++i)
			{
				horde[i].announce(); // Announce each Zombie
			}
			deleteHorde(horde); // Free the allocated memory
		}
		return 0;
	}
	
}


