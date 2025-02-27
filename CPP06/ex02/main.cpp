/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/19 09:14:56 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base*	generate( void );
void	identify( Base* p );
void	identify( Base& p );

int	main( void )
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << ":" << std::endl;
		Base* base = generate();
		identify( base );
		identify( *base );
		delete base;
	}
	std::cout << std::endl << "Test with nullptr" << std::endl;
	{
		Base* base2 = nullptr;
		identify(base2);
		identify(*base2);
	}
};
