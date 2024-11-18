/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:24:38 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 17:42:13 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool checkInt(const std::string& str)
{
    try {
        size_t checkedChars = 0;
        std::stoi(str, &checkedChars);
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
        std::stof(str);  // Try to convert to float
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
}

bool checkDouble(const std::string& str)
{
    try {
        std::stod(str);  // Try to convert to double
        return true;
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
    if (str == "nan")
    {
        std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
        std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
    }
}

void ScalarConverter::convert(const std::string& str) {


        if (str == "-inf" || str == "+inf" || str == "inf" || str == "inff" || str == "nan" || str == "-inff" || str == "+inff")
        {
            printPseudo(str);
        }
        else 
        {
            int x = checkType(str);
            std::cout << x << std::endl;
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
                    int num = std::stoi(str);
                    std::cout << "char: ";
                    if (isprint(num)) {
                        std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
                    } else {
                        std::cout << "non-displayable" << std::endl;
                    }
                    std::cout << "int: " << num << std::endl;
                    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
                    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
                    break;
                }
                case 3:
                {
                    float fnum = std::stof(str);
                    std::cout << "char: ";
                    if (isprint(fnum)) {
                        std::cout << "'" << static_cast<char>(fnum) << "'" << std::endl;
                    } else {
                        std::cout << "non-displayable" << std::endl;
                    }
                    std::cout << "int: " << static_cast<int>(fnum) << std::endl;
                    std::cout << "float: " << std::fixed << std::setprecision(1) << fnum << "f" << std::endl;
                    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(fnum) << std::endl;
                    break;
                }
                case 4:
                {
                    double dnum = std::stod(str);
                    std::cout << "char: ";
                    if (isprint(dnum)) {
                        std::cout << "'" << static_cast<char>(dnum) << "'" << std::endl;
                    } else {
                        std::cout << "non-displayable" << std::endl;
                    }
                    std::cout << "int: " << static_cast<int>(dnum) << std::endl;
                    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(dnum) << "f" << std::endl;
                    std::cout << "double: " << std::fixed << std::setprecision(1) << dnum << std::endl;
                }
                case 0:
                    std::cout << "conversion impossible" << std::endl;
            }
        }
}
