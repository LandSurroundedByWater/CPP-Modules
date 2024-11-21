/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/19 14:24:53 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"


void printStringElement(std::string& x) {
	std::cout << x << " " << std::endl;
}

void printIntElement(int& x) {
	std::cout << x << " " << std::endl;
}

int main( void ) {
	std::string arr[] = {"Wow", "Great", "Wonderful"};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	::iter(arr, size, printStringElement);
	std::cout << std::endl;
	::iter(arr, size, printStringCapitalized);
	std::cout << std::endl;

	int intArr[] = {1, 2, 3};
	size = sizeof(intArr) / sizeof(intArr[0]);

	::iter(intArr, size, printIntElement);
	::iter(intArr, size, printMultipleTwo);
	return 0;
}
