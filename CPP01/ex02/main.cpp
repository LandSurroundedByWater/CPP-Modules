/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:09:59 by timo              #+#    #+#             */
/*   Updated: 2024/08/10 13:31:24 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "Memory address of the string: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << strPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &strREF << std::endl;

	std::cout << "Value of the str: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *strPTR << std::endl;
	std::cout << "Value of stringREF: " << strREF << std::endl;
	return 0;
}