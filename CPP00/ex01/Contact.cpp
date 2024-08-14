/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:53:30 by timo              #+#    #+#             */
/*   Updated: 2024/08/09 10:38:43 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName() const  {  return this->_firstName; }

std::string Contact::getLastName() const { return this->_lastName; }

std::string Contact::getNickName() const { return (this->_nickName); }

std::string Contact::getPhoneNumber() const  { return (this->_phoneNumber);  }

std::string Contact::getDarkestSecret() const  { return (this->_darkestSecret);  }

bool isValidInput(const std::string& name);

bool Contact::setFirstName(std::string name)
{
	if (!isValidInput(name))
		return false;
	for (char c : name) 
	{
		if (!std::isalpha(c) && !std::isspace(c) && c != '-') 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_firstName = name;
	return true;
}

bool Contact::setLastName(std::string name)
{
	if (!isValidInput(name))
		return false;
	for (char c : name) 
	{
		if (!std::isalpha(c) && !std::isspace(c) && c != '-') 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_lastName = name;
	return true;
}

bool Contact::setNickName(std::string name)
{
	if (!isValidInput(name))
		return false;
	for (char c : name) 
	{
		if (!std::isalpha(c) && !std::isspace(c) && c != '-') 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_nickName = name;
	return true;
}

bool Contact::setPhoneNumber(std::string number)
{
	size_t start = 0;
	if (!isValidInput(number))
		return false;
	if (number [0] == '+')
		start++;
	for (size_t i =  start; i < number.size(); ++i)  
	{
		char c = number[i];
		if (!std::isdigit(c) && !std::isspace(c)) 
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_phoneNumber = number;
	return true;
}

bool Contact::setDarkestSecret(std::string secret)
{
	if (!isValidInput(secret))
		return false;
	for (char c : secret) 
	{
		if (!std::isprint(c) && !std::isspace(c))
		{
			std::cout << "Invalid input." << std::endl;
			return false;
		}
	}
	this->_darkestSecret = secret;
	return true;
}

bool isValidInput(const std::string& name) 
{
	if (name.empty())
	{
		std::cout << "Invalid input, field cannot be empty." << std::endl;
		return false;
	}
	for (char c : name) 
	{
		if (!std::isspace(c))
			return true;
	}
	std::cout << "Invalid input." << std::endl;
	return false;
}