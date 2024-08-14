/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:13:46 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/11 13:27:15 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::intro(void) const
{
	std::cout << "Commands:" << std::endl;
	std::cout << "ADD - add new contact" << std::endl;
	std::cout << "SEARCH - search contact from phonebook" << std::endl;
	std::cout << "EXIT - exit program"<< std::endl;
	std::cout << std::endl;
	std::cout << "Please, give a command."<< std::endl;
	std::cout << "> ";
}

void PhoneBook::addContact(void)
{
	std::string str;

	str = "";
	if (this->_index > 7)
	{
		std::cout << "New contact overwrites contact " << this->contacts[this->_index % 8].getFirstName() << " " \
		<< this->contacts[this->_index % 8].getLastName() << std::endl;
	}
	while (!std::cin.eof())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, str);
	
		if (this->contacts[this->_index % 8].setFirstName(str))
			break;
	}

	str = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, str);
	
		if (this->contacts[this->_index % 8].setLastName(str))
			break;
	}
	
	str = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, str);
	
		if (this->contacts[this->_index % 8].setNickName(str))
			break;
	}
	
	str = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, str);
	
		if (this->contacts[this->_index % 8].setPhoneNumber(str))
			break;
	}
	
	str = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter your darkest secret: ";
		std::getline(std::cin, str);
	
		if (this->contacts[this->_index % 8].setDarkestSecret(str))
			break;
	}
	_index++;
	std::cout << "Contact added!" << std::endl;
}

void PhoneBook::printSpecificContact (void) const
{
	std::string str = "";
	int index_search = 0;

	std::cout << "Enter index (0-7): " << std::endl;
	std::cout << "> ";
	while (getline(std::cin, str))
	{
		if (str.length() !=  1 || !std::isdigit(str[0]))
		{
			std::cout << "Invalid input." << std::endl;
			std::cout << "Enter index (0-7): " << std::endl;
			std::cout << "> ";
			continue;
		}
		index_search = atoi(str.c_str());
		if (index_search > 7 || index_search < 0)
		{
			std::cout << "Invalid input." << std::endl;
			std::cout << "Enter index (0-7): " << std::endl;
			std::cout << "> ";
			continue;
		}
		index_search = atoi(str.c_str());
		if (index_search  > this->_index - 1)
		{
			std::cout << "No contact with that index." << std::endl;
			std::cout << "Enter index (0-7): " << std::endl;
			std::cout << "> ";
			continue;
		}
		else
		{
			std::cout << "First name: " << this->contacts[index_search].getFirstName() << std::endl;
			std::cout << "Last name: " << this->contacts[index_search].getLastName() << std::endl;
			std::cout << "Nickname: " << this->contacts[index_search].getNickName() << std::endl;
			std::cout << "Phone number: " << this->contacts[index_search].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << this->contacts[index_search].getDarkestSecret() << std::endl;
			break;
		}
	
	}
}

void PhoneBook::searchContact (void) const
{	
	std::string str = "";
	std::string fname = "";
	std::string lname = "";
	std::string nname = "";
	
	if (this->_index == 0)
	{
		std::cout << "No contacts in phonebook." << std::endl;
		std::cout << "> ";
		return;
	}

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	
	for (int i = 0; i < 8; i++) 
	{
		if (this->contacts[i].getFirstName().length() > 10)
			fname = this->contacts[i].getFirstName().substr(0, 9) + '.';
		else
			fname = this->contacts[i].getFirstName();
		if (this->contacts[i].getLastName().length() > 10)
			lname = this->contacts[i].getLastName().substr(0, 9) + '.';
		else
			lname = this->contacts[i].getLastName();
		if (this->contacts[i].getNickName().length() > 10)
			nname = this->contacts[i].getNickName().substr(0, 9) + '.';
		else
			nname = this->contacts[i].getNickName();
		
		std::cout << "|"
		<< std::setw(10) << std::right << i << "|"
		<< std::setw(10) << std::right << fname << "|"
		<< std::setw(10) << std::right << lname << "|"
		<< std::setw(10) << std::right << nname << "|"
		<< std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	
	printSpecificContact();
	std::cout << std::endl;
	intro();
}
