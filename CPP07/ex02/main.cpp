/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/21 14:00:00 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"


int main( void ) {
	Array<int> emptyArray;

	Array<int> originalArray(10);;
	for (size_t i = 0; i < 10; i++)
	{
		originalArray[i] = i;
	}
	std::cout << "ORIG ARRAY" << std::endl;
	
	for (int i : originalArray)
	{
		std::cout << i << std::endl;
	}

	std::cout << "COPY CONSTRUCTOR" << std::endl;
	Array<int> copiedArray = originalArray;
	originalArray[3] = 1;
	copiedArray[8] = 1;
	std::cout << "COPIED" << std::endl;
	for (int i : copiedArray)
	{
		std::cout << i << std::endl;
	}
	std::cout << "ORIGINAL" << std::endl;
	for (int i : originalArray)
	{
		std::cout << i << std::endl;
	}
	std::cout << "COPY ASSIGNMENT OPERATOR" << std::endl;

	copiedArray = originalArray;
	for (int i : copiedArray)
	{
		std::cout << i << std::endl;
	}

	//this segfaults 	std::cout << copiedArray[11] << std::endl
	
	//but this works
	try
	{
		std::cout << copiedArray[11] << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	;
		

	
	return 0;
}
