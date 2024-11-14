/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:41:03 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/06 10:32:44 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap 
{
	public:
		FragTrap(std::string name);
		FragTrap (const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void attack (const std::string& target);
		void highFivesGuys(void);
};

#endif
