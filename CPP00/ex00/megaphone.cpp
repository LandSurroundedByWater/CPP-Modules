/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:51:25 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/11 13:26:22 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

std::string ft_trim(std::string& str)
{
	auto start = str.begin();
	auto end = str.end();

	while (start != end && std::isspace(static_cast<unsigned char>(*start)))
		++start;
	if (start == end)
		return "";
	while (end != start && std::isspace(static_cast<unsigned char>(*(end - 1))))
		--end;
	return std::string(start, end);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		if (std::strlen(argv[i]) < 1)
		continue;
		std::string str = argv[i];
		std::string arg = ft_trim(str);
		for (char &c : arg) 
			c = std::toupper(static_cast<unsigned char>(c)); 
		std::cout << arg << ' ';
	}
	std::cout << std::endl;
}
