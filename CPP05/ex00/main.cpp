/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/14 15:22:15 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
	try
	{
		Bureaucrat deffe;
		std::cout << deffe << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
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
		timo.increaseGrade();
		
		std::cout << timo << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//-----------Using exit in error handling
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

	
	///----------------So this is not done

	try
	{
		Bureaucrat boss("Boss2", 0);
		Bureaucrat bigboss("Timo2", 200);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
	return 0;
}

