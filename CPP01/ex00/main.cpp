/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:50:38 by timo              #+#    #+#             */
/*   Updated: 2024/08/14 12:55:47 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	//create zombie to heap from here
	Zombie *zombie = new Zombie("Timo");
	zombie->announce();
	delete zombie;
	
	//create zombie to heap using newZombie function	
	Zombie *zombie2 = newZombie("Jaska");
	zombie2->announce();
	delete(zombie2);
	
	//create zombie to stack using randomChump function
	randomChump("Erkka");
}


