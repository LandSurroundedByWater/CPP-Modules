/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:20:22 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/05 10:55:11 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <cstddef>
#include <string>


template <typename T>
void printMultipleTwo (const T& x) {
	std::cout << x * 2 << std::endl;
}


template <typename T>
void iter(T* a, size_t size, void (*f)(const T&)) {
    for (size_t i = 0; i < size; i++)
        (*f)(a[i]);
}

template <typename T>
void iter(T* a, size_t size, void (*f)(T&)) {
    for (size_t i = 0; i < size; i++)
        (*f)(a[i]);
}




#endif