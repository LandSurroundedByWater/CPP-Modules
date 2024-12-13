/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:20:22 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/12 13:26:03 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T max(T& a, T& b) {
	return (a > b) ? a : b;
}

template <typename T>
T min(T& a, T& b) {
	return (a < b) ? a : b;
}


#endif