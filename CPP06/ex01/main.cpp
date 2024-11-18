/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 18:54:30 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Serializer.hpp"

int main(void) {
   
    Data originalData{42};
    Data *ptr = &originalData;

    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;
    
    Data *deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data value: " << deserializedPtr->n << std::endl;

    return 0;
}
