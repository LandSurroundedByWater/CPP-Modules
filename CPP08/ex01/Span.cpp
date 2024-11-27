/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:35:14 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/27 09:29:54 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) :
	_n(n) {}

/*Span::Span(const std::vector<int>& v) :
	_n(v.size()),
	_v(v) {}

Span::Span(std::vector<int>&& v) :
	_n(v.size()),
	_v(std::move(v)) {}
*/
Span::Span(const Span& other) :
	_n(other._n) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_n = other._n;
	}
	return *this;
}


void Span::addNumber(int n) {
	if (_v.size() >= _n) {
		throw std::overflow_error("No more numbers can be added.");
	}
	_v.push_back(n);
}	

void Span::addRandomNumbers(unsigned int n, int min, int max) {
	if (_v.size() + n > _n) {
		throw std::overflow_error("No more numbers can be added.");
	}
	for (unsigned int i = 0; i < n; ++i) {
		_v.push_back(rand() % (max - min + 1) + min);
	}
}

Span::~Span() {}

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
