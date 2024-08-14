/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:09:20 by timo              #+#    #+#             */
/*   Updated: 2024/08/08 15:02:34 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
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

std::string getCurrentTimestamp(); 

void	Account::_displayTimestamp( void )
{
	std::cout << getCurrentTimestamp() << " ";
}

//GETTERS

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ){ return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) {  return _totalNbWithdrawals; }

// NEEDED FUNCTIONS

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
}
	
void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
			<< ";p_amount:" << this->_amount - deposit 
			<< ";deposit:" << deposit 
			<< ";amount:" << this->_amount 
			<< ";nb_deposits:" << this->_nbDeposits 
			<< std::endl;
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
	std::cout << "index:" << this->_accountIndex 
			<< ";p_amount:" << this->_amount + withdrawal 
			<< ";withdrawal:" << withdrawal 
			<< ";amount:" << this->_amount 
			<< ";nb_withdrawals:" << this->_nbWithdrawals 
			<< std::endl;
	return (true);
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
			<< ";amount:" << this->_amount 
			<< ";deposits:" << this->_nbDeposits 
			<< ";withdrawals:" << this->_nbWithdrawals 
			<< std::endl;
}

std::string getCurrentTimestamp() {
    std::time_t now = std::time(NULL);
    std::tm *timeinfo = std::localtime(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeinfo);

    return std::string(buffer);
}


