/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:50:38 by timo              #+#    #+#             */
/*   Updated: 2024/07/19 11:54:18 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie = new Zombie("timo");
	zombie->announce();
	delete zombie;

	
	Zombie randomZombie("Zombies");
	randomZombie.randomChump("heppu");
}


