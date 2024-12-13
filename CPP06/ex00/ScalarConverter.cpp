/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:24:38 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/12 10:36:59 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool checkInt(const std::string& str)
{
	try {
		size_t checkedChars = 0;
		std::stoll(str, &checkedChars);
		return checkedChars == str.length();
	} catch (const std::invalid_argument& e) {
		return false;
	} catch (const std::out_of_range& e) {
		return false;
	}
}

bool checkFloat(const std::string& str)
{
	try {
		std::string strWithoutF = str;
		if (strWithoutF.back() == 'f') {
			strWithoutF.pop_back();
		}
		size_t checkedChars = 0;
		std::stof(strWithoutF, &checkedChars);
		return checkedChars == strWithoutF.length();
	} catch (const std::invalid_argument& e) {
		return false;
	} catch (const std::out_of_range& e) {
		return false;
	}
}

bool checkDouble(const std::string& str)
{
	try {
		size_t checkedChars = 0;
		std::stod(str, &checkedChars);
		return checkedChars == str.length();
	} catch (const std::invalid_argument& e) {
		return false;
	} catch (const std::out_of_range& e) {
		return false;
	}
}
	

int checkType(const std::string& str)
{   
	if (str.length() == 1 && !isdigit(str[0]))
		return 1;
	if (checkInt(str))
		return 2;
	if (checkFloat(str))
		return 3;
	if (checkDouble(str))
		return 4;
	return 0;
}

void printPseudo(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible"  << std::endl;
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (str == "+inf" ||  str == "+inff" || str == "inf" || str == "inff")
	{
			std::cout << "float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
			std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str) {


		if (str == "-inf" || str == "+inf" || str == "inf" || str == "inff" || str == "nan" || str == "nanf" || str == "-inff" || str == "+inff")
		{
			printPseudo(str);
		}
		else 
		{
			int x = checkType(str);
			switch(x)
			{
				case 1:
				{
					char c = str[0];
					std::cout << "char: '" << c << "'" << std::endl;
					std::cout << "int: " << static_cast<int>(c) << std::endl;
					std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
					std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
					break;
				}
				case 2:
				{
					try {
						int num = std::stoi(str);
						std::cout << "char: ";
						if (num >= 0 && num <= 255) {
							if (isprint(num)) {
								std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
							} else {
								std::cout << "Non displayable" << std::endl;
							}
						} else {
							std::cout << "Not in range of ASCII" << std::endl;
						}
						std::cout << "int: " << num << std::endl;
						std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
						std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
					} catch (const std::out_of_range& e) {
						std::cout << "Out of range for int." << std::endl;
					} catch (const std::invalid_argument& e) {
						std::cout << "Invalid input for int conversion." << std::endl;
				}
					break;
				}
				case 3:
				{
					try
					{
						float fnum = std::stof(str);
						std::cout << "char: ";
						if (fnum >= 0 && fnum <= 255) {
							if (isprint(fnum)) {
								std::cout << "'" << static_cast<char>(fnum) << "'" << std::endl;
							} else {
								std::cout << "non-displayable" << std::endl;
							}
						} else {
							std::cout << "invalid character" << std::endl;
						}
						std::cout << "int: " << static_cast<int>(fnum) << std::endl;
						std::cout << "float: " << std::fixed << std::setprecision(1) << fnum << "f" << std::endl;
						std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(fnum) << std::endl;
					} catch (const std::invalid_argument& e) {
						std::cout << "Invalid input for float conversion." << std::endl;
					} catch (const std::out_of_range& e) {
						std::cout << "Out of range for float conversion." << std::endl;
					}
					break;
				}
				case 4:
				{
					try
					{
						double dnum = std::stod(str);
						std::cout << "char: ";1
						
						if (dnum >= 0 && dnum <= 255) {
							if (isprint(dnum)) {
								std::cout << "'" << static_cast<char>(dnum) << "'" << std::endl;
							} else {
								std::cout << "non-displayable" << std::endl;
							}
						} else {
							std::cout << "invalid character" << std::endl;
						}
						std::cout << "int: " << static_cast<int>(dnum) << std::endl;
						std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(dnum) << "f" << std::endl;
						std::cout << "double: " << std::fixed << std::setprecision(1) << dnum << std::endl;
					} catch (const std::invalid_argument& e) {
						std::cout << "Invalid input for double conversion." << std::endl;
					} catch (const std::out_of_range& e) {
						std::cout << "Out of range for double conversion." << std::endl;
					}
				}
				case 0:
					std::cout << "conversion impossible" << std::endl;
			}
		}
}
