/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:16:07 by timo              #+#    #+#             */
/*   Updated: 2024/08/08 09:10:06 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string input;

	std::cout << std::endl;
	std::cout << "    Welcome to awesome phonebook!" << std::endl;
	std::cout <<  std::endl;
	book.intro();

	while (getline(std::cin, input))
	{
		if ((input.compare("ADD")) == 0)
		{
			book.addContact();
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
