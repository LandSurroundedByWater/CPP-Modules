/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:35:14 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/07 09:26:01 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <utility>
#include <iterator>

Span::Span() {}

Span::Span(unsigned int n) :
	_n(n) {}

Span::Span(const Span& other) :
	_n(other._n) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_n = other._n;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_v.size() > _n) {
		throw std::overflow_error("No more numbers can be added.");
	}
	_v.push_back(n);
}

void Span::addRandomNumbers(unsigned int n, int min, int max) {
	for (unsigned int i = 0; i < n; ++i) {
		addNumber(rand() % (max - min + 1) + min);
	}
}

void Span::addUniqueRandomNumbers(unsigned int n, int min, int max) {
	for (unsigned int i = 0; i < n; ++i) {
		int num = rand() % (max - min + 1) + min;
		if (find(_v.begin(), _v.end(), num) != _v.end()) {
			--i;
			continue;
		}
		else
		addNumber(num);
	}
}

unsigned int Span::shortestSpan() {
	if (_v.size() < 2) {
		throw std::invalid_argument("Not enough numbers.");
	}
	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());

	std::vector<unsigned int> diffs;
	std::adjacent_difference(sorted.begin(), sorted.end(), std::back_inserter(diffs));

	unsigned int minSpan = *std::min_element(diffs.begin() + 1, diffs.end());
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
