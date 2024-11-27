/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/27 12:46:15 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	Span span1 = Span(5);

	try
	{
		span1.addNumber(5);
		span1.addNumber(3);
		span1.addNumber(17);
		span1.addNumber(9);
		span1.addNumber(11);
		span1.addNumber(13);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Span1 shortest span: " << span1.shortestSpan() << std::endl;
	std::cout << "Span1 longest span: " << span1.longestSpan() << std::endl;	

	Span span2 = Span(16);
	Span span3 = Span(16000);
	try
	{
		span2.addNumber(5);
		std::cout << "Span2 shortest span: " << span2.shortestSpan() << std::endl;
		std::cout << "Span2 longest span: " << span2.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		span2.addRandomNumbers(10, -10000, 10000);
		std::cout << "Span2 shortest span: " << span2.shortestSpan() << std::endl;
		std::cout << "Span2 longest span: " << span2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		span3.addRandomNumbers(15000, -15000, 10000);
		std::cout << "Span3 shortest span: " << span3.shortestSpan() << std::endl;
		std::cout << "Span3 longest span: " << span3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	
}