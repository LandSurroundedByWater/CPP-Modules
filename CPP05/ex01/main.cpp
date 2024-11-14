/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/14 15:55:38 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
	try
	{
		Form form1("Form1", false, 120, 3);
		std::cout << form1 << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}

	try
	{
		Bureaucrat boss("Boss", 060);
		Bureaucrat bigboss("Timo", 200);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}


	
}

