/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:14:23 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/26 12:14:59 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap 
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	
	public:
		ClapTrap(std::string name);
		ClapTrap::ClapTrap(std::string name);
		ClapTrap& ClapTrap::operator=(const ClapTrap& other);
		~ClapTrap();
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


		//getters and setters
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		
		void setHitPoints(int hitPoints);
		void setEnergyPoints(int energyPoints);
		void setAttackDamage(int attackDamage);
};

#endif