/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:50:38 by timo              #+#    #+#             */
/*   Updated: 2024/07/19 12:00:30 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 8;

    Zombie* horde = zombieHorde(N, "HordeZombie");

    if (sizeof(horde) > 0) 
{
        for (int i = 0; i < N; ++i) {
            horde[i].announce(); // Announce each Zombie
        }
        deleteHorde(horde); // Free the allocated memory
    }

    return 0;
}


