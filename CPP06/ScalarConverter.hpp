/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:24:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 12:56:48 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter {
public:
	static void convert(const std::string& str);

	enum Type{
	TYPECHAR,
	TYPEINT,
	TYPEFLOAT,
	TYPEDOUBLE,
	};

private:
	// Constructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP
