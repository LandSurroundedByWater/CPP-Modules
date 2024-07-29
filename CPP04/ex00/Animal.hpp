/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:21:02 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/26 10:46:21 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
		std::string type;

	public:
		
		Animal(std::string type);
		~Animal();

	std::string getType() const;
	virtual void makeSound();
}
	

#endif

