/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/02 17:34:52 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "RPN.hpp"


int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage example: " << argv[0] << " \"1 2 +\"" << std::endl;
		return 1;
	}
	try{
		std::string inputString = argv[1];
		RPN rpn(inputString);
		rpn.executeRPN();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}