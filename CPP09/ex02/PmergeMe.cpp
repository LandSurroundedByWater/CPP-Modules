/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:24:08 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/05 17:08:38 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv, ContainerType type) : listOrphan(-1), vectorOrphan(-1)
{
	if (type == LIST)
		loadListFromArgs(argv);
	else if (type == VECTOR)
		loadVectorFromArgs(argv);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}


std::list <int> PmergeMe::getOriginalList() const {
	return _originalList;
}

std::vector <int> PmergeMe::getOriginalVector() const {
	return _originalVector;
}

std::list <std::pair<int, int>> PmergeMe::getListPairs() const {
	return _listPairs;
}

std::vector <std::pair<int, int>> PmergeMe::getVectorPairs() const {
	return _vectorPairs;
}

std::list <int> PmergeMe::getFinalList() const {
	return _finalList;
}

std::vector <int> PmergeMe::getFinalVector() const {
	return _finalVector;
}


PmergeMe::~PmergeMe() {}

void PmergeMe::loadListFromArgs(char **argv)
{	
	//making list from args
	for (int i = 1; argv[i] != nullptr; i++)
	{
		int num = std::stoi(argv[i]); 
		if (num < 0)
			throw NegativeNumberException();

		_originalList.push_back(num);
	}
	//taking care of orphan
	if (_originalList.size() % 2 != 0)
	{
		listOrphan = _originalList.back();
		_originalList.pop_back(); 
	}
	//making pairs to list
	auto it = _originalList.begin();
	while (it != _originalList.end()) {
		int first = *it;
		if (++it != _originalList.end()) {
			_listPairs.emplace_back(first, *it);
			++it;
		}
	}
}


void PmergeMe::loadVectorFromArgs(char **argv)
{
	//making vector from args
	for (int i = 1; argv[i] != nullptr; i++)
	{
		int num = std::stoi(argv[i]);
		if (num < 0)
			throw NegativeNumberException();
		_originalVector.push_back(num);
	}
	//taking care of orphan
	if (_originalVector.size() % 2 != 0)
	{
		vectorOrphan = _originalVector.back();
		_originalVector.pop_back();
	}
	//making pairs to vector
	for (size_t i = 0; i < _originalVector.size(); i += 2) {
		_vectorPairs.emplace_back(_originalVector[i], _originalVector[i + 1]);
	}
}




void PmergeMe::makeSortingWithList() {
	for (auto& pair : _listPairs) {
		if (pair.first > pair.second) {
			std::swap(pair.first, pair.second);
		}
	}
	_listPairs.sort([](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.second < b.second;
	});
	for(auto& pair : _listPairs) {
		_finalList.push_back(pair.second);
	}
	for (auto& pair : _listPairs) {
		auto it = _finalList.begin();
		while (it != _finalList.end() && *it < pair.first) {
			++it;
		}
		_finalList.insert(it, pair.first);
	}
	//setting orphan
	if (listOrphan != -1) {
		auto it = _finalList.begin();
		while (it != _finalList.end() && *it < listOrphan) {
			++it;
		}
		_finalList.insert(it, listOrphan);
	}
}

void PmergeMe::makeSortingWithVector() {
	for (auto& pair : _vectorPairs) {
		if (pair.first > pair.second) {
			std::swap(pair.first, pair.second);
		}
	}
	std::sort(_vectorPairs.begin(), _vectorPairs.end(), 
		  [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
			  return a.second < b.second;
		  });
	for(auto& pair : _vectorPairs) {
		_finalVector.push_back(pair.second);
	}
	for (auto& pair : _vectorPairs) {
		auto it = std::lower_bound(_finalVector.begin(), _finalVector.end(), pair.first);
		_finalVector.insert(it, pair.first);
	}
	if (vectorOrphan != -1) {
		auto it = std::lower_bound(_finalVector.begin(), _finalVector.end(), vectorOrphan);
		_finalVector.insert(it, vectorOrphan);
	}
}


