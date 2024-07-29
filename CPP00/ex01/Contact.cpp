/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:53:30 by timo              #+#    #+#             */
/*   Updated: 2024/07/18 16:05:27 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

std::string Contact::get_firstName() const 
{
    return this->_firstName;
}

std::string Contact::get_lastName() const 
{
    return this->_lastName;
}

std::string Contact::get_nickName() const
{
	return (this->_nickName);
}

std::string Contact::get_phoneNumber() const
{
	return (this->_phoneNumber);
}

std::string Contact::get_darkestSecret() const
{
	return (this->_darkestSecret);
}

//-------------------------------------------------------------

bool Contact::set_firstName(std::string name)
{
	if (name == "")
	{
		std::cout << "First name cannot be empty." << std::endl;
		return false;
	}
	for (char c : name) 
	{
		if (!std::isalpha(c) && !std::isspace(c)) 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_firstName = name;
	return true;
}

bool Contact::set_lastName(std::string name)
{
	if (name == "")
	{
		std::cout << "Invalid input, Last name cannot be empty." << std::endl;
		return false;
	}
	for (char c : name) 
	{
		if (!std::isalpha(c) && !std::isspace(c)) 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_lastName = name;
	return true;
}

bool Contact::set_nickName(std::string name)
{
	if (name == "")
	{
		std::cout << "Nickname cannot be empty." << std::endl;
		return false;
	}
	for (char c : name) 
	{
		if (!std::isalpha(c) && !std::isspace(c)) 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_nickName = name;
	return true;
}

bool Contact::set_phoneNumber(std::string number)
{
	if (number == "")
	{
		std::cout << "Phone number cannot be empty." << std::endl;
		return false;
	}
	for (char c : number) 
	{
		if (!std::isdigit(c) && !std::isspace(c) && c != '+') 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_phoneNumber = number;
	return true;
}

bool Contact::set_darkestSecret(std::string secret)
{
	if (secret == "")
	{
		std::cout << "Your secret cannot be empty." << std::endl;
		return false;
	}
	for (char c : secret) 
	{
		if (!std::isalpha(c) && !std::isspace(c)) 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_darkestSecret = secret;
	return true;
}
