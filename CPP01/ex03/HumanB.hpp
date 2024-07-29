/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:31:34 by timo              #+#    #+#             */
/*   Updated: 2024/07/26 11:18:46 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;
	
	public:
		HumanB(std::string name);
		HumanB(const HumanB& other);
		HumanB operator=(const HumanB& other);
		~HumanB();

		void attack(void) const;
		void setWeapon(Weapon& weapon);
};

#endif
