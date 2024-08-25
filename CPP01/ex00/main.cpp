/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:50:38 by timo              #+#    #+#             */
/*   Updated: 2024/08/23 08:26:24 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	//create zombie to heap calling class
	Zombie *zombie = new Zombie("Timo");
	zombie->announce();
	delete zombie;

	//create zombie to stack calling class
	Zombie zombie2("Makke");
	zombie2.announce();
	
	//create zombie to heap using newZombie function	
	Zombie *zombie3 = newZombie("Jaska");
	zombie3->announce();
	delete(zombie3);
	
	//create zombie to stack using randomChump function
	randomChump("Erkka");
}


