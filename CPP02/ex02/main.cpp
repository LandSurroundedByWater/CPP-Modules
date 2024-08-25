/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:59:51 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/24 09:26:11 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}


/*int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.06f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << " a = b = " << (a + b) << std::endl;
	std::cout << " a - b = " << (a - b) << std::endl;
	std::cout << " a * b = " << (a * b) << std::endl;
	std::cout << " b / a = " << (b / a) << std::endl;
	
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	if (a > b) 
		std::cout << "hell yeah" << std::endl;
	else
		std::cout << "sorry no" << std::endl;
	return 0;
}*/

