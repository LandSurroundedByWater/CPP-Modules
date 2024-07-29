/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:20:30 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/26 10:47:57 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal(std::type) : type(type)
{
	std::string << "New Animal " << type << "born" <<std::endl; 
}

~Animal() {}

std::string Animal::get_type() const{
	return type;
}

void Animal::makeSound()
{
	std::count << "Some generic animal Sound" << std::endl;
}