/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:24:38 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 12:57:35 by tsaari           ###   ########.fr       */
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
        std::stoi(str);
        return true;
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
        std::cout << "float: " << -std::numeric_limits<float>::infinity() << std::endl;
    }
    else if (str == "+inf" ||  str == "+inff")
    
    
    
    if (str == "nan")
        
    
}

void ScalarConverter::convert(const std::string& str) {


        if (str == "-inf" || str == "+inf" || str == "nan" || str == "-inff" || str == "+inff")
        {
            printPseudo(str);
        }
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
                if (str == "-inff" || str == "inff")
                {
                    std::cout << "char: impossible";
                    std::cout << "int: impossible"  << std::endl;
                    std::cout << "float: " << std::fixed << std::setprecision(1) << fnum << "f" << std::endl;
                }
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
    /*    try {
        
        if (str.length() == 1 && !isdigit(str[0])) {
            char c = str[0];
            std::cout << "char: '" << c << "'" << std::endl;
            // Convert to int, float, and double
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        }
        // Check if the string can be converted to an integer
        else if (str.find_first_not_of("0123456789") == std::string::npos) {
            // This is an integer
            int num = std::stoi(str);
            std::cout << "char: ";
            if (num >= 32 && num <= 126) {
                std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
            } else {
                std::cout << "non-displayable" << std::endl;
            }
            std::cout << "int: " << num << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
        }
        // Check if the string can be converted to a float
        else if (str.find_first_not_of("0123456789.-f") == std::string::npos && str.find('f') != std::string::npos) {
            // This is a float
           ;
        }
        // Check if the string can be converted to a double
        else if (str.find_first_not_of("0123456789.-") == std::string::npos) {
            // This is a double
            double dnum = std::stod(str);
            std::cout << "char: ";
            if (dnum >= 32 && dnum <= 126) {
                std::cout << "'" << static_cast<char>(dnum) << "'" << std::endl;
            } else {
                std::cout << "non-displayable" << std::endl;
            }
            std::cout << "int: " << static_cast<int>(dnum) << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(dnum) << "f" << std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << dnum << std::endl;
        }
        else {
            throw std::invalid_argument("Invalid type format");
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }*/

}