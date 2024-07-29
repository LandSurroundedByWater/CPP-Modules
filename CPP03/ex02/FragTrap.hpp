/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:41:03 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/26 12:43:56 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
public:

	FragTrap(std::string name);
	FragTrap::FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other)
	~FragTrap() override;

	//void attack (const std::string& target) override;
	void highFivesGuys(void);
};

#endif
