/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:09:39 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:09:41 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
	this->_index = 0;
	std::cout << "Brains created" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brains copied" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->_ideas[i] = other._ideas[i];
		this->_index = other._index;
		std::cout << "Brains assignment operator called" << std::endl;
	}
	return *this;
}

Brain::~Brain() 
{
	std::cout << "Brains destroyed" << std::endl;
}

void Brain::addIdea(std::string idea)
{
	if (_index < 100)
	{
		this->_ideas[_index] = idea;
		_index++;
		std::cout << "added new idea: " << idea << "!" << std::endl;
	}
	else
	{
		std::cerr << "Brains are full of ideas, cannot add more!" << std::endl;
	}
}

std::string Brain::getIdea(int index)
{
	if (index < 0 || index > 99)
	{
		std::cerr << "!ndex must be integer between 0 and 99!" << std::endl;
		return "";
	}
	else
	{
		if (this->_ideas[index].length() == 0)
		{
			std::cerr << "No idea in that index!" << std::endl;
			return "";
		}
		else 
		{
			return (this->_ideas[index]);
		}
	}
}




