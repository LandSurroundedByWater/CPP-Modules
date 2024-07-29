/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:26:59 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/19 10:15:17 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//creates a new Zombie object on the stack and calls the announce method
void Zombie::randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}
//delete zombie; is not needed because the object is created on the stack and 
//will be destroyed when the function ends