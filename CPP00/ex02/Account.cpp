/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:09:20 by timo              #+#    #+#             */
/*   Updated: 2024/07/19 09:34:40 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}
int	Account::getNbAccounts( void )
{
	return _nbAccounts;	
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;	
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;	
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";amount:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
	
void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount < withdrawal)
	{
		
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalAmount -= withdrawal;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

std::string getCurrentTimestamp() {

    std::time_t now = std::time(nullptr);
    std::tm *timeinfo = std::localtime(&now);

    std::ostringstream timeString;
    timeString << std::put_time(timeinfo, "%Y%m%d_%H%M%S");
    
    return timeString.str();
}

void	Account::_displayTimestamp( void )
{
	std::cout << getCurrentTimestamp() << " ";
}
