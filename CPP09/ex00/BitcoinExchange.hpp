/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:38:08 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/18 13:20:31 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>


class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string& sourceFile);
		~BitcoinExchange();
		
		void exchangeBitcoins(const std::string& filename);
	
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		std::map<std::string, float> _dateValueMap;
		void loadDataFromFile(const std::string& filename);
		void processLine(const std::string& line);
		double findFromSource(const std::string& targetDate);
};