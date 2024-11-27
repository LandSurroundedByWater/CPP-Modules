/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/27 09:37:03 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>
#include <deque>

int main()
{
	
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

	Span span2 = Span(10000);

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

	std::cout << "Span1 shortest span: " << span1.shortestSpan() << std::endl;
	std::cout << "Span1 longest span: " << span1.longestSpan() << std::endl;	
	
}