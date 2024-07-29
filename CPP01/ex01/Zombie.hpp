/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:14:23 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/19 12:05:32 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
	private:
		std::string _name;
	
	public:
		Zombie();
		Zombie(const std::string &name);
		~Zombie();

		void announce(void) const;
		void setZombieName(std::string name);

};

Zombie* zombieHorde(int N, const std::string &name);
void deleteHorde(Zombie* horde);
#endif
