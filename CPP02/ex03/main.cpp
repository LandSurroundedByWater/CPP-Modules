/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:59:51 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/24 09:44:53 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main ( void ) 
{
	if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(1, 1) ) == true ) 
	{
		std::cout << "Point(1, 1) is in the triangle of Point(0, 0), Point(10, 30), Point(20, 0)" << std::endl;
	} 
	else
	{
		std::cout << "Point(1, 1) is not in the triangle Point(0, 0), Point(10, 30), Point(20, 0)" << std::endl;
	}

	if ( bsp( Point(0, 0), Point(10.0f, 30), Point(20, 0), Point(-0.1f, 0) ) == true ) 
	{
		std::cout << "Point(-0.1f, 0) is in the triangle of Point(0, 0), Point(10.0f, 30), Point(20, 0)" << std::endl;
	} 
	else
	{
		std::cout << "Point(-0.1f, 0) is not in the triangle of Point(0, 0), Point(10.0f, 30), Point(20, 0)" << std::endl;
	}
	return 0;
}