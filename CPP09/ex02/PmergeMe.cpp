/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:24:08 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/24 12:56:07 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv, ContainerType type) : listOrphan(0), vectorOrphan(0), isOrphan(false)
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


std::list <unsigned int> PmergeMe::getOriginalList() const {
	return _originalList;
}

std::vector <unsigned int> PmergeMe::getOriginalVector() const {
	return _originalVector;
}

std::list <std::pair<unsigned int, unsigned int>> PmergeMe::getListPairs() const {
	return _listPairs;
}

std::vector <std::pair<unsigned int, unsigned int>> PmergeMe::getVectorPairs() const {
	return _vectorPairs;
}

std::list <unsigned int> PmergeMe::getFinalList() const {
	return _finalList;
}

std::vector <unsigned int> PmergeMe::getFinalVector() const {
	return _finalVector;
}


PmergeMe::~PmergeMe() {}

void PmergeMe::loadListFromArgs(char **argv)
{	
	//making list from args
	for (unsigned int i = 1; argv[i] != nullptr; i++)
	{
		unsigned int num = std::stoi(argv[i]); 
		if (num < 0)
			throw NegativeNumberException();

		_originalList.push_back(num);
	}
	//taking care of orphan
	if (_originalList.size() % 2 != 0)
	{
		listOrphan = _originalList.back();
		_originalList.pop_back(); 
		isOrphan = true;
	}
	//making pairs to list
	auto it = _originalList.begin();
	while (it != _originalList.end()) {
		unsigned int  first = *it;
		if (++it != _originalList.end()) {
			_listPairs.emplace_back(first, *it);
			++it;
		}
	}
}


void PmergeMe::loadVectorFromArgs(char **argv)
{
	//making vector from args
	for (unsigned int i = 1; argv[i] != nullptr; i++)
	{
		unsigned int num = std::stoi(argv[i]);
		if (num < 0)
			throw NegativeNumberException();
		_originalVector.push_back(num);
	}
	//taking care of orphan
	if (_originalVector.size() % 2 != 0)
	{
		vectorOrphan = _originalVector.back();
		_originalVector.pop_back();
		isOrphan = true;
	}
	//making pairs to vector
	for (size_t i = 0; i < _originalVector.size(); i += 2) {
		_vectorPairs.emplace_back(_originalVector[i], _originalVector[i + 1]);
	}
}


void PmergeMe::mergeSortList(std::list<std::pair<unsigned int, unsigned int>>::iterator start,
							 std::list<std::pair<unsigned int, unsigned int>>::iterator mid,
							 std::list<std::pair<unsigned int, unsigned int>>::iterator end,
							 std::list<std::pair<unsigned int, unsigned int>>& tempList)
{
	auto left = start;
	auto right = mid;

	tempList.clear();
	
	while (left != mid && right != end)
	{
		if (left->first < right->first)
			tempList.push_back(*left++);
		else
			tempList.push_back(*right++);
	}

	while (left != mid)
		tempList.push_back(*left++);

	while (right != end)
		tempList.push_back(*right++);

	auto it = start;
	for (auto& pair : tempList)
		*it++ = pair;
}




void PmergeMe::mergeSplitList(std::list<std::pair<unsigned int, unsigned int>>::iterator start,
							  std::list<std::pair<unsigned int, unsigned int>>::iterator end)
{
	if (start == end || std::next(start) == end)
		return;

	auto mid = start;
	std::advance(mid, std::distance(start, end) / 2);
	mergeSplitList(start, mid);
	mergeSplitList(mid, end);
	std::list<std::pair<unsigned int, unsigned int>> tempList;
	mergeSortList(start, mid, end, tempList);
}


void PmergeMe::makeSortingWithList() {
	for (auto& pair : _listPairs) {
		if (pair.first < pair.second) {
			std::swap(pair.first, pair.second);
		}
	}
	mergeSplitList(_listPairs.begin(), _listPairs.end());
	
	for(auto& pair : _listPairs) {
		_finalList.push_back(pair.first);
	}
	for (auto& pair : _listPairs) {
		auto it = _finalList.begin();
		while (it != _finalList.end() && *it < pair.second) {
			++it;
		}
		_finalList.insert(it, pair.second);
	}
	//setting orphan
	if (isOrphan) {
		auto it = _finalList.begin();
		while (it != _finalList.end() && *it < listOrphan) {
			++it;
		}
		_finalList.insert(it, listOrphan);
	}
}


void PmergeMe::mergeSortVector(unsigned int start, unsigned int mid, unsigned int end, std::vector <std::pair<unsigned int , unsigned int>>& tempVector)
{
	unsigned int i = start;
	unsigned int j = mid + 1;
	tempVector.clear(); 

	while (i <= mid && j <= end)
	{
		if (_vectorPairs[i].first < _vectorPairs[j].first)
			tempVector.push_back(_vectorPairs[i++]);
		else
			tempVector.push_back(_vectorPairs[j++]);
	}
	while (i <= mid)
	{
		tempVector.push_back(_vectorPairs[i]);
		i++;
	}
	while (j <= end)
	{
		tempVector.push_back(_vectorPairs[j]);
		j++;
	}
	for (unsigned int k = 0; k < tempVector.size(); k++)
		_vectorPairs[start + k] = tempVector[k];
}



void PmergeMe::mergeSplitVector(unsigned int start, unsigned int end)
{
	 if (start >= end)
		return;

	unsigned int mid = (start + end) / 2;
	mergeSplitVector(start, mid);
	mergeSplitVector(mid + 1, end);
	std::vector<std::pair<unsigned int, unsigned int>> tempVector;
	mergeSortVector(start, mid, end, tempVector); 
}

void PmergeMe::makeSortingWithVector() {
	for (auto& pair : _vectorPairs) {
		if (pair.first < pair.second) {
			std::swap(pair.first, pair.second);
		}
	}
	mergeSplitVector(0, _vectorPairs.size() - 1);
	for(auto& pair : _vectorPairs) {
		_finalVector.push_back(pair.first);
	}
	for (auto& pair : _vectorPairs) {
		auto it = std::lower_bound(_finalVector.begin(), _finalVector.end(), pair.second);
		_finalVector.insert(it, pair.second);
	}
	if (isOrphan) {
		auto it = std::lower_bound(_finalVector.begin(), _finalVector.end(), vectorOrphan);
		_finalVector.insert(it, vectorOrphan);
	}
}


