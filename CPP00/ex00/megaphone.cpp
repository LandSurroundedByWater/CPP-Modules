/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:51:25 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/17 15:42:16 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != 0; j++)
		{
			if (argv[i][j] == ' ' && ((j == 0) || argv[i][j + 1] == 0))
				continue;
			else
				std::cout << static_cast<char>(toupper(argv[i][j]));
		}
		std::cout << ' ';
	}
	std::cout << std::endl;
}

