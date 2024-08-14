/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:31:34 by timo              #+#    #+#             */
/*   Updated: 2024/08/10 15:24:35 by tsaari           ###   ########.fr       */
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
		~HumanB();
		void attack(void) const;
		void setWeapon(Weapon& weapon);
};

#endif
