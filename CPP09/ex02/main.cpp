/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/24 13:09:52 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "PmergeMe.hpp"
#include <chrono>
#include <iomanip>
#include <vector>
#include <list>


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
		auto start = std::chrono::high_resolution_clock::now();
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
		auto end = std::chrono::high_resolution_clock::now();	
		durationList = std::chrono::duration_cast<std::chrono::duration<double, std::micro>>(end - start);
		
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
		auto start = std::chrono::high_resolution_clock::now();
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
		auto end = std::chrono::high_resolution_clock::now();	
		durationVector = std::chrono::duration_cast<std::chrono::duration<double, std::micro>>(end - start);

	}
	catch (const PmergeMe::NegativeNumberException &e) {
        std::cerr << e.what() << std::endl;
        return 1; 
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

	///checking if results match and printing result
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
    << std::fixed << std::setprecision(6) << durationList.count() << " microseconds" << std::endl;

	std::cout << "Time to process a range of " << listSize << " elements with std::vector: "
    << std::fixed << std::setprecision(6) << durationVector.count() << " microseconds" << std::endl;

	/*	std::cout << "Time to process a range of " << listSize << " elements with std::list: "
	<< std::fixed << std::setprecision(6) << durationList.count() << " us" << std::endl;

	std::cout << "Time to process a range of " << listSize << " elements with std::vector: "
	<< std::fixed << std::setprecision(6) << durationVector.count() << " us" << std::endl;
	*/


	return 0;
}



