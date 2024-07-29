/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:41:03 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/26 12:19:35 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
public:

	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator(const ScavTrap& other); 
	~ScavTrap() override;

	void attack (const std::string& target) override;
	void guardGate();
};

#endif
