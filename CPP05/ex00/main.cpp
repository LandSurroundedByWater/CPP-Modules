/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/29 08:49:34 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
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
		std::cout << timo << std::endl;
		timo.decreaseGrade();
		std::cout << timo << std::endl;
		timo.increaseGrade();
		std::cout << timo << std::endl;
		timo.increaseGrade();
		std::cout << timo << std::endl;
		timo.increaseGrade();
		std::cout << timo << std::endl;
		timo.increaseGrade();
		std::cout << timo << std::endl;
		timo.increaseGrade();
		std::cout << timo << std::endl;
		timo.increaseGrade();
		std::cout << timo << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "BUREAUCRATS, WHICH GRADE IS OUT OF SCOPE" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat bigboss("Timo", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "END" << std::endl;
	
	return 0;
}

