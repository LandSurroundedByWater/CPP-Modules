/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/05 11:03:02 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


void printStringElement(const  std::string& x) {
	std::cout << x << " " << std::endl;
}

void printIntElement(const int& x) {
	std::cout << x << " " << std::endl;
}

void printFloatElement(const float& x) {
	std::cout << x << " " << std::endl;
}

void printStringCapitalized(const std::string& x) { 
    std::string copy = x;
    for (char& c : copy) {
        c = std::toupper(c);
    }
    std::cout << copy << " " << std::endl;
}

void modifyIntElement(int& x)
{
	x = 42;
}

int main( void ) {
	std::string arr[] = {"Wow", "Great", "Wonderful"};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	::iter(arr, size, printStringElement);
	std::cout << std::endl;
	iter(arr, size, printStringCapitalized);
	std::cout << std::endl;

	int intArr[] = {1, 2, 3};
	size = sizeof(intArr) / sizeof(intArr[0]);

	::iter(intArr, size, printIntElement);
	::iter(intArr, size, printMultipleTwo);
	std::cout << std::endl;
	float floatArr[] = {1.2, 3.6654, 7.43};
    size = sizeof(floatArr) / sizeof(floatArr[0]);

    iter(floatArr, size, printFloatElement);
    iter(floatArr, size, printMultipleTwo);
	std::cout << std::endl;
	int intArrToModify[] = {1, 2, 3};
	size = sizeof(intArrToModify) / sizeof(intArr[0]);
	::iter(intArrToModify, size, printIntElement);
	::iter(intArrToModify, size, modifyIntElement);
	::iter(intArrToModify, size, printIntElement);

	return 0;
}

