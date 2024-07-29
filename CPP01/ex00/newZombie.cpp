/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:55:00 by timo              #+#    #+#             */
/*   Updated: 2024/07/19 10:11:09 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//dynamically allocates memory for a new Zombie object and returns a pointer to it
Zombie* newZombie(std::string name) {

    Zombie *zombie = new Zombie(name);
    return zombie;
}