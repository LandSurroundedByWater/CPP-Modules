/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:16:07 by timo              #+#    #+#             */
/*   Updated: 2024/07/18 18:34:01 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string input;

	std::cout << "***Welcome to awesome phonebook!***" << std::endl;
	book.intro();

	while (getline(std::cin, input))
	{
		if ((input.compare("ADD")) == 0)
		{
			book.add_contact();
			std::cout << "> ";
		}
		else if ((input.compare("SEARCH")) == 0)
		{
			book.searchContact();
			
		}
		else if ((input.compare("EXIT")) == 0)
			break;
		else
		{
			std::cout << "Command not found!" << std::endl;
			std::cout << "> ";
		}
	}
	return (0);
}