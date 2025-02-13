/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/05 17:17:51 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "PmergeMe.hpp"
#include <chrono>
#include <iomanip>




#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted subarrays into one sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
	{
		leftArr[i] = arr[left + i];
	}
    for (int i = 0; i < n2; i++) {
		rightArr[i] = arr[mid + 1 + i];
	}
	

	for (auto i: leftArr)
		std::cout << "left: " << i << " ";
	std::cout << std::endl;

	for (auto i: rightArr)
		std::cout << "right: " << i << " ";
	std::cout << std::endl;
    // Merge the temp arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr (if any)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr (if any)
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the middle index

        mergeSort(arr, left, mid);       // Sort first half
        mergeSort(arr, mid + 1, right);  // Sort second half

        merge(arr, left, mid, right);    // Merge sorted halves
    }
}

// Helper function to print the vector
void printVector(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Driver code
int main() {
    vector<int> largerElements = {15, 8, 23, 4, 42, 16, 7, 12, 27, 3};

    cout << "Original array: ";
    printVector(largerElements);

    mergeSort(largerElements, 0, largerElements.size() - 1);

    cout << "Sorted array: ";
    printVector(largerElements);

    return 0;
}




/*
int main(int argc, char** argv) {

	std::chrono::duration<double> durationList;
	std::chrono::duration<double> durationVector;
	std::string listBefore;
	std::string vectorBefore;
	std::string listAfter;
	std::string vectorAfter;
	int listSize = 0; 
	if (argc < 2) {
		std::cout << "Usage example: " << argv[0] << " 1-3000 random nubers separated by \" \"" << std::endl;
		return 1;
	}
	//sorting with list
	try{
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		std::list <unsigned int> mergeList;
		PmergeMe listed(argv, PmergeMe::LIST);
		
		for (auto i : listed.getOriginalList())
		{
			
			if (i == listed.getOriginalList().back())
				listBefore += std::to_string(i);
			else
				listBefore += std::to_string(i) + ", ";
		}
		listSize = listed.getOriginalList().size();
		listed.makeSortingWithList();
		for (auto i : listed.getFinalList())
		{
			if (i == listed.getFinalList().back())
				listAfter += std::to_string(i);
			else
				listAfter += std::to_string(i) + ", ";
		}
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();	
		durationList = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	 catch (const PmergeMe::NegativeNumberException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
	//soting with vector
	try{
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		PmergeMe vectorized(argv, PmergeMe::VECTOR);
		for (auto i : vectorized.getOriginalVector())
		{
			if (i == vectorized.getOriginalVector().back())
				vectorBefore += std::to_string(i);
			else
				vectorBefore += std::to_string(i) + ", ";
		}
		listSize = vectorized.getOriginalVector().size();
		
		vectorized.makeSortingWithVector();
		
		for (auto i : vectorized.getFinalVector())
		{
			if (i == vectorized.getFinalVector().back())
				vectorAfter += std::to_string(i);
			else
				vectorAfter += std::to_string(i) + ", ";
		}
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();	
		durationVector = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

	}
	catch (const PmergeMe::NegativeNumberException &e) {
        std::cerr << e.what() << std::endl;
        return 1; 
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

	if (vectorAfter != listAfter || vectorBefore != listBefore)
	{
		std::cerr << "Error: The results are not the same!" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Before: " << listBefore << std::endl;
		std::cout << "After: " << listAfter << std::endl;
	}
	std::cout << "Time to process a range of " << listSize << " elements with std::list: "
	<< std::fixed << std::setprecision(6) << durationList.count() << " seconds" << std::endl;

	std::cout << "Time to process a range of " << listSize << " elements with std::vector: "
	<< std::fixed << std::setprecision(6) << durationVector.count() << " seconds" << std::endl;
	
	return 0;
}
*/


