/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:53:21 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/05 11:41:20 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include "Array.hpp"

//------------------CONSTRUCTORS AND DESTRUCTOR---------------------

template <typename T>
Array<T>::Array() : _data(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : _data(new T[size]), _size(size) {}

template <typename T>
Array<T>::Array(Array& other) : _data(new T[other._size]), _size(other._size) {
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
    if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[other._size];
		for (size_t i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
    delete [] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= 0 && index < _size)
		return _data[index];
	else
		throw std::out_of_range("Index out of range");

}

template <typename T>
unsigned int Array<T>::size() {return _size;}

// for for loops

template <typename T>
T* Array<T>::begin() { return _data; }

template <typename T>
T* Array<T>::end() { return _data + _size; }