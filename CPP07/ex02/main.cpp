/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/05 12:03:04 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"


int main( void ) {
	Array<int> emptyArray;

	try
	{
		Array<int> originalArray(10);
		for (size_t i = 0; i < 10; i++)
		{
			originalArray[i] = i;
		}
		std::cout << "ORIG ARRAY" << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << originalArray[i] << std::endl;
		}
		std::cout << "COPY CONSTRUCTOR" << std::endl;
		Array<int> copiedArray = originalArray;
		
		originalArray[3] = 1;
		copiedArray[8] = 1;
		
		std::cout << "COPIED" << std::endl;
		for (size_t i = 0; i < copiedArray.size() ; i++)
		{
			std::cout << copiedArray[i] << std::endl;
		}
		
		std::cout << "ORIGINAL" << std::endl;
		for (size_t i = 0; i < originalArray.size(); i++)
		{
			std::cout << originalArray[i] << std::endl;
		}
		std::cout << "COPY ASSIGNMENT OPERATOR" << std::endl;
		
		copiedArray = originalArray;
		std::cout << "COPIED" << std::endl;
		
		copiedArray[5] = 1;
		
		for (size_t i = 0; i < copiedArray.size(); i++)
		{
			std::cout << copiedArray[i] << std::endl;
		}
		
		std::cout << "ORIGINAL" << std::endl;
		for (size_t i = 0; i < originalArray.size(); i++)
		{
			std::cout << originalArray[i] << std::endl;
		}
	}
	catch( std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
