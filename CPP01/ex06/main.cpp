/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:18:17 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/10 15:38:58 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl h;
	if (argc != 2)
	{
		std::cout << "invalid number of arguments" << std::endl;
		std::cout << "give one of following arguments: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
	else
	{
		h.complain(argv[1]);
	}
	return (0);
}