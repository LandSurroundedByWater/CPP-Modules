/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:24:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 18:31:03 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data {
	int n;

	Data(int x) : n(x) {};
	Data() : n(0) {};
};	

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);

	static Data* deserialize(uintptr_t raw);

private:
	
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();
};

#endif // SERIALIZER_HPP
