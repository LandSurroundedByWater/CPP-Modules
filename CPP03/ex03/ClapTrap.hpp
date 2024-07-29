/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:14:23 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/25 14:00:49 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap 
{
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	
	public:
		 ClapTrap(std::string name);
		virtual ~ClapTrap();
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


		//getters and setters for testing purposes
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		
		void setHitPoints(int hitPoints);
		void setEnergyPoints(int energyPoints);
		void setAttackDamage(int attackDamage);

		std::string getName() const;
};

#endif