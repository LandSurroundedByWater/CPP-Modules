/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:09:59 by timo              #+#    #+#             */
/*   Updated: 2024/07/19 12:18:04 by timo             ###   ########.fr       */
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

	std::cout << "Value pointed to by stringPTR: " << *strPTR << std::endl;
	std::cout << "Value of stringREF: " << strREF << std::endl;
	return 0;
}