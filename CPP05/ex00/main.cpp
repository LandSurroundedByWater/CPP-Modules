/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/27 12:22:25 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
	std::cout << "Try Default" << std::endl;
	try
	{
		Bureaucrat deffe;
		std::cout << deffe << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Try Jack with grade 220" << std::endl;
	try
	{
		Bureaucrat jack("Jack", 220);
		std::cout << jack << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "Try Jack with grade 20" << std::endl;
	try
	{
		Bureaucrat jack("Jack", 20);
		std::cout << jack << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat timo("Timo", 3);
		std::cout << timo << std::endl;
		timo.increaseGrade();
		timo.increaseGrade();
		std::cout << timo << std::endl;
		timo.increaseGrade();
		
		std::cout << timo << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat boss("Boss", 060);
		Bureaucrat bigboss("Timo", 200);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "END" << std::endl;
	
	return 0;
}

