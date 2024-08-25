/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:18:17 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/12 09:42:03 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl h;
	h.complain("INFO");
	std::cout << std::endl;
	h.complain("INFO");
	std::cout << std::endl;
	h.complain("ERROR");
	std::cout << std::endl;
	h.complain("WARNING");
	std::cout << std::endl;
	h.complain("DEBUG");
	h.complain("aksnka");
	return (0);
}