/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:59:14 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/27 09:26:47 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <utility>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:

		Span();
		Span(unsigned int n);
		//Span(const std::vector<int>& v);
		//Span(std::vector<int>&& v);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
	
		void addRandomNumbers(unsigned int n, int min, int max);
		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};


#endif