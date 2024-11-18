/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 20:53:36 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base*	generate( void );
void	identify( Base* p );
void	identify( Base& p );

int	main( void )
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 6; i++)
	{
		Base* base = generate();
		identify( base );
		identify( *base );
		delete base;
	}
};
