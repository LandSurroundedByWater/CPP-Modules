/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:59:14 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/07 11:31:14 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>


class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:

		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
	
		void addRandomNumbers(unsigned int n, int min, int max);
		void addUniqueRandomNumbers(unsigned int n, int min, int max);
		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};


#endif