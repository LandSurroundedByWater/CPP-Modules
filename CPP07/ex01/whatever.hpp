/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:20:22 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/19 14:22:08 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <cstddef>

template <typename T>
void printStringCapitalized(T& x) {
	  for (char& c : x) {
        c = std::toupper(c);
    }
	std::cout << x << " " << std::endl;
}

template <typename T>
void printMultipleTwo (T& x) {
	std::cout << x * 2 << std::endl;
}


template <typename T>
void iter(T* a, size_t size, void (*f)(T&)) {
	for (size_t i = 0; i < size; i++)
		(*f)(a[i]);
}

#endif