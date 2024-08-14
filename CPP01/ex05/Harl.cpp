/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:38:05 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/14 10:57:32 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}
void Harl::warning( void )
{
	std::cerr << "[WARNING]" << std::endl;
	std::cerr << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}
void Harl::error( void )
{
	std::cerr << "[ERROR]" << std::endl;
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::unknown( void )
{
	std::cout << "Unknown complaint level" << std::endl;
	std::cout << "give one of following levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cout << std::endl;
}

Harl::Level Harl::getLevel(const std::string& level) const
{
	if (level == "DEBUG") return DEBUG;
	if (level == "INFO") return INFO;
	if (level == "WARNING") return WARNING;
	if (level == "ERROR") return ERROR;
	return UNKNOWN;
}

void Harl::complain( std::string level )
{
	t_function functions [5]= { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::unknown};
	
	Level currentLevel = getLevel(level);
	switch (currentLevel)
	{
		case DEBUG:
		{
			(this->*functions[DEBUG])();
			break;
		}
		case INFO:
		{
			(this->*functions[INFO])();
			break;
		}
		case WARNING:
		{
			(this->*functions[WARNING])();
			break;
		}
		case ERROR:
		{
			(this->*functions[ERROR])();
			break;
		}
		default:
		{
			(this->*functions[UNKNOWN])();
			break;
		}
	}
	return ;
}
