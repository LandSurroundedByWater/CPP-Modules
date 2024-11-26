/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:35:14 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/26 16:53:39 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

unsigned int Span::shortestSpan() {
	if (_v.size() < 2) {
		throw std::invalid_argument("Not enough numbers.");
	}
	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		unsigned int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan) {
			minSpan = diff;
		}
	} 
	return minSpan;
}


unsigned int Span::longestSpan() {
	if (_v.size() < 2) {
		throw std::invalid_argument("Not enough numbers.");
	}
	int minElement = *std::min_element(_v.begin(), _v.end());
	int maxElement = *std::max_element(_v.begin(), _v.end());

	return maxElement - minElement;
}