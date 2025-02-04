/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:46:10 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/02 13:39:45 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dataBase)
{
	loadDataFromFile(dataBase);
}
	

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_dateValueMap = other._dateValueMap;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_dateValueMap = other._dateValueMap;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::findFromSource(const std::string& targetDate) {
	auto it = _dateValueMap.lower_bound(targetDate);
	if (it == _dateValueMap.begin()) {
		throw std::invalid_argument("Error: No date " + targetDate + ". Bitcoin's usage as a currency started in 2009.");
	}
	if (it != _dateValueMap.end() && it->first == targetDate) {
		return it->second;
	}
	--it;
	return it->second;
}
//checks first that string is ok, then that date is possible and not in future.
bool isValidDate(const std::string& targetDate) {
	int year, month, day;
	char dash1, dash2;

	std::istringstream dateStream(targetDate);
	if (!(dateStream >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
		return false; 
	}

	std::time_t t = std::time(nullptr);
	std::tm* currentTime = std::localtime(&t);

	int currentYear = currentTime->tm_year + 1900;
	int currentMonth = currentTime->tm_mon + 1;
	int currentDay = currentTime->tm_mday;

	if (year < 0 || year > currentYear) return false;
	if ((year == currentYear && month > currentMonth) || month < 1 || month > 12) return false;
	if ((year == currentYear && month == currentMonth && day > currentDay) || day < 1 || day > 31) return false;

	std::tm timeStruct = {};
	timeStruct.tm_year = year - 1900;
	timeStruct.tm_mon = month - 1;
	timeStruct.tm_mday = day;

	if (std::mktime(&timeStruct) == -1) {
		return false;
	}
	return (timeStruct.tm_year == year - 1900 &&
			timeStruct.tm_mon == month - 1 &&
			timeStruct.tm_mday == day);
}

void BitcoinExchange::processLine(const std::string& line) {

	std::istringstream iss(line);
	std::string date, separator;
	float value;

	if (!(iss >> date >> separator >> value) || !isValidDate(date) || separator != "|") {
		throw std::invalid_argument("Error: bad input => " + line);
	}
	if (value < 0) {
		throw std::out_of_range("Error: not a positive number.");
	}
	if (value > 1000) {
		throw std::out_of_range("Error: too large a number.");
	}
	float price = findFromSource(date);
	if (price != -1) {
		std::cout << date << " => " << value << " = " << price * value << std::endl;
	} else {
		throw std::runtime_error("Error: No price found for date " + date);
	}
}

void BitcoinExchange::exchangeBitcoins(const std::string& filename)
{
	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		throw std::runtime_error("Error: Could not open input file " + filename);
	}
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		try {
			processLine(line);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
	}
}

void BitcoinExchange::loadDataFromFile(const std::string& filename) {
	std::ifstream sourceFile(filename);
	if (!sourceFile.is_open()) {
		throw std::runtime_error("Error: Could not open source file " + filename);
	}
	std::string line;
	std::getline(sourceFile, line);
	while (std::getline(sourceFile, line)) {
		size_t commaPos = line.find(',');
		std::string date = line.substr(0, commaPos);
		float value = std::stof(line.substr(commaPos + 1));
		_dateValueMap[date] = value;
	}
}

