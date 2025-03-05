/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:24:08 by tsaari            #+#    #+#             */
/*   Updated: 2025/03/05 14:44:26 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <climits>


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv, ContainerType type) : dequeOrphan(-1), vectorOrphan(-1), isOrphan(false)
{
	if (type == DEQUE)
		loadDequeFromArgs(argv);
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

PmergeMe::~PmergeMe() {}


//----------------------------GETTERS-------------------------------------

std::deque <int> PmergeMe::getOriginalDeque() const {
	return _originalDeque;
}


std::vector <int> PmergeMe::getOriginalVector() const {
	return _originalVector;
}

std::deque <std::pair<int, int>> PmergeMe::getDequePairs() const {
	return _dequePairs;
}

std::vector <std::pair<int, int>> PmergeMe::getVectorPairs() const {
	return _vectorPairs;
}


std::deque <int> PmergeMe::getFinalDeque() const {
	return _finalDeque;
}

std::vector <int> PmergeMe::getFinalVector() const {
	return _finalVector;
}

//----------------------------LOAD FUNCTIONS-------------------------------------

void PmergeMe::loadDequeFromArgs(char **argv)
{
	//deque from args
	for (int i = 1; argv[i] != nullptr; i++)
	{
		int num = std::stoi(argv[i]);
		if (num < 0)
			throw NegativeNumberException();
		_originalDeque.push_back(num);
	}
	//take care of orphan
	if (_originalDeque.size() % 2 != 0)
	{
		dequeOrphan = _originalDeque.back();
		_originalDeque.pop_back();
		isOrphan = true;
	}
	//make pairs
	for (size_t i = 0; i < _originalDeque.size(); i += 2) {
		_dequePairs.emplace_back(_originalDeque[i], _originalDeque[i + 1]);
	}
	if (isOrphan)
		_originalDeque.push_back(dequeOrphan);
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
		isOrphan = true;
	}
	//making pairs to vector
	for (size_t i = 0; i < _originalVector.size(); i += 2) {
		_vectorPairs.emplace_back(_originalVector[i], _originalVector[i + 1]);
	}
	if(isOrphan)
		_originalVector.push_back(vectorOrphan);
}

//----------------------------DEQUE-------------------------------------

std::deque<int> generateJacobsthalDeque(int n) {
	std::deque<int> jacobsthal = {0, 1};
	while ((int)jacobsthal.size() < n) {
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

// Function to manually sort with minimal swaps
void manualSort(std::deque<int>& arr) {
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			std::swap(arr[j], arr[j - 1]); // Swap adjacent elements if out of order
			j--;
		}
	}
}

void PmergeMe::insertUsingJacobsthalDeque() {
    std::deque<int> jacobsthal = generateJacobsthalDeque(_dequePairs.size() + 2);
    for (size_t i = 0; i < _dequePairs.size(); i++) {
        // Ensure pos doesn't exceed the size of _finalDeque
        size_t pos = std::min(jacobsthal[i], (int)_finalDeque.size());
        
        std::cout << "jacobsthal[" << i << "]: " << jacobsthal[i] << ", pos: " << pos << std::endl;

        if (pos >= 0 && pos <= _finalDeque.size()) {
            // Insert the second value of the pair at the calculated position
            _finalDeque.insert(_finalDeque.begin() + pos, _dequePairs[i].second);
        } else {
            std::cerr << "Invalid position: " << pos << std::endl;
        }
    }
    // Optionally, manually sort the deque if necessary
    manualSort(_finalDeque);
}
/*void PmergeMe::insertUsingJacobsthalDeque() {                                            ////////segfaults
	std::deque<int> jacobsthal = generateJacobsthalDeque(_dequePairs.size() + 2);
	for (size_t i = 0; i < _dequePairs.size(); i++) {
		size_t pos = std::min(jacobsthal[i], (int)_finalDeque.size());
		std::cout << "pos: " << pos << std::endl;
		if (pos >= 0 && pos <= _finalDeque.size())
			_finalDeque.insert(_finalDeque.begin() + pos, _dequePairs[i].second);
		else {
			std::cerr << "Invalid position: " << pos << std::endl;
		}
	}
	manualSort(_finalDeque);
}*/


void PmergeMe::mergeSortDeque(int start, int mid, int end, std::deque <std::pair<int , int>>& tempDeque)
{
	int i = start;
	int j = mid + 1;
	tempDeque.clear(); 

	while (i <= mid && j <= end)
	{
		if (_dequePairs[i].first < _dequePairs[j].first)
			tempDeque.push_back(_dequePairs[i++]);
		else
			tempDeque.push_back(_dequePairs[j++]);
	}
	while (i <= mid)
	{
		tempDeque.push_back(_dequePairs[i]);
		i++;
	}
	while (j <= end)
	{
		tempDeque.push_back(_dequePairs[j]);
		j++;
	}
	for (int k = 0; k < (int)tempDeque.size(); k++)
		_dequePairs[start + k] = tempDeque[k];
}

void PmergeMe::mergeSplitDeque(int start, int end)
{
	 if (start >= end)
		return;

	int mid = (start + end) / 2;
	mergeSplitDeque(start, mid);
	mergeSplitDeque(mid + 1, end);
	std::deque<std::pair<int, int>> tempDeque;
	mergeSortDeque(start, mid, end, tempDeque); 
}

void PmergeMe::makeSortingWithDeque() {
	for (auto& pair : _dequePairs) {
		if (pair.first < pair.second) {
			std::swap(pair.first, pair.second);
		}
	}
	mergeSplitDeque(0, _dequePairs.size() - 1);
	for(auto& pair : _dequePairs) {
		_finalDeque.push_back(pair.first);
	}
	insertUsingJacobsthalDeque();
	if (isOrphan)
		_finalDeque.insert(std::lower_bound(_finalDeque.begin(), _finalDeque.end(), dequeOrphan), dequeOrphan);
}




//----------------------------Vector-------------------------------------

std::vector<int> generateJacobsthalVector(int n) {
	std::vector<int> jacobsthal = {0, 1};  // Base cases
	while ((int)jacobsthal.size() < n) {
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

void manualSort(std::vector<int>& arr) {
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			std::swap(arr[j], arr[j - 1]); // Swap adjacent elements if out of order
			j--;
		}
	}
}


void PmergeMe::insertUsingJacobsthalVector() {
	std::vector<int> jacobsthal = generateJacobsthalVector(_vectorPairs.size() + 2);
	for (size_t i = 0; i < _vectorPairs.size(); i++) {
		int pos = std::min(jacobsthal[i], (int)_finalVector.size()); 
		_finalVector.insert(_finalVector.begin() + pos, _vectorPairs[i].second); 
	}
	manualSort(_finalVector);
}


void PmergeMe::mergeSortVector(int start, int mid, int end, std::vector <std::pair<int , int>>& tempVector)
{
	int i = start;
	int j = mid + 1;
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
	for (int k = 0; k < (int)tempVector.size(); k++)
		_vectorPairs[start + k] = tempVector[k];
}



void PmergeMe::mergeSplitVector(int start, int end)
{
	 if (start >= end)
		return;

	int mid = (start + end) / 2;
	mergeSplitVector(start, mid);
	mergeSplitVector(mid + 1, end);
	std::vector<std::pair<int, int>> tempVector;
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
	insertUsingJacobsthalVector();
	if (isOrphan)
		_finalVector.insert(std::lower_bound(_finalVector.begin(), _finalVector.end(), vectorOrphan), vectorOrphan);
}


