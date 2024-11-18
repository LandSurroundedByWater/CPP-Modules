/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 09:52:48 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
   
    if (argc != 2) {
        std::cerr << "Invalid amount of arguments! Use: ./convert <value>" << std::endl;
        return 1; 
    }

    // The input value to be converted
    std::string input = argv[1];

    // Call ScalarConverter::convert to process the input
    ScalarConverter::convert(input);

    return 0; // Exit successfully
}
