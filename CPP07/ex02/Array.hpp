/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:30:30 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/21 14:03:20 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T* _data;
	unsigned int _size;
public:
	Array();
	Array(unsigned int size);
	Array(Array& other);
	Array &operator=(const Array &other);
	
	~Array();

	T& operator[](unsigned int index);
	unsigned int size();

	T* begin();
    T* end();
};

#include "Array.tpp"

#endif






