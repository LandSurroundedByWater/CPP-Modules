/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:14:23 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/26 11:17:28 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		HumanA(const HumanA &other);
		HumanA& operator=(const HumanA &other);
		~HumanA();
		void attack(void) const;
};

#endif