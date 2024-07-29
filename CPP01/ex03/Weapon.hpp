/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:14:23 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/26 11:56:46 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string _type;
    
    public:
        Weapon(const std::string &type);
        Weapon(const Weapon &other);
        Weapon& operator=(const Weapon &other);
        ~Weapon();

        std::string getType(void) const;

        void setType(std::string type);
};


#endif
