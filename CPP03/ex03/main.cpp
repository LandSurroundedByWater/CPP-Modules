/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:49:39 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/10 10:12:09 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "----------creating FragTrap Bob-----------" << std::endl;
	std::cout << std::endl;
	FragTrap bob = FragTrap("Bob");
	bob.attack("a worm");

	std::cout << std::endl;
	std::cout << "----------copy constructor Byb from Bob-----------" << std::endl;
	std::cout << std::endl;
	FragTrap byb = bob;
	byb.attack("a beatle");
	bob.takeDamage(9);

	std::cout << std::endl;
	std::cout << "----------creating DiamondTraps-----------" << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "----------creating bib-----------" << std::endl;
	std::cout << std::endl;
	
	DiamondTrap *bib = new DiamondTrap("bib");	
	
	std::cout << std::endl;
	std::cout << "-----------------copy constructor bub from bib--------------" << std::endl;
	std::cout << std::endl;
	
	DiamondTrap bub = bib;
	bub.whoAmI();
	
	std::cout << std::endl;
	std::cout << "-------------creating Bab-----------" << std::endl;
	std::cout << std::endl;
	
	DiamondTrap bab = DiamondTrap("Bab");
	bab.whoAmI();
	
	std::cout << std::endl;
	std::cout << "-------------copy assign operator from Bib to Bab-----------" << std::endl;
	std::cout << std::endl;
	
	bab = bib;
	bab.whoAmI();
	bib.whoAmI();
	
	std::cout << std::endl;
	std::cout << "-------------checking functions------------"  << std::endl;
	std::cout << std::endl;
	
	bib->whoAmI();
	bib->attack("a human");
	bib->highFivesGuys();
	bib->beRepaired(5);
	
	std::cout << std::endl;
	std::cout << "----------End of test, Destroy all-----------" << std::endl;
	std::cout << std::endl;
	delete(bib);
}
