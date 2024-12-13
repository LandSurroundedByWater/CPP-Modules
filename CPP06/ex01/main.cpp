/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/12 12:55:17 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <cstdint>
#include "Serializer.hpp"

int main(void) {

	Data originalData{345};
	Data *ptr = &originalData;

	std::cout << "pointer address before: " << ptr << std::endl;
	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;
	
	Data *deserializedPtr = Serializer::deserialize(raw);
	std::cout << "pointer address  after: " << deserializedPtr << std::endl;
	std::cout << "Deserialized Data value: " << deserializedPtr->n << std::endl;
	
	return 0;
}
