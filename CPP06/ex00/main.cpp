/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 18:28:48 by tsaari           ###   ########.fr       */
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

    std::string input = argv[1];

    ScalarConverter::convert(input);

    return 0;
}
