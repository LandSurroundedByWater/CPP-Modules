/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/03/10 09:39:02 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "PmergeMe.hpp"
#include <chrono>
#include <iomanip>
#include <vector>
#include <deque>


int main(int argc, char** argv) {

	std::chrono::duration<double> durationDeque;
	std::string dequeBefore;
	std::string dequeAfter;
	
	std::chrono::duration<double> durationVector;
	std::string vectorBefore;
	std::string vectorAfter;
	int containerSize = 0; 
	if (argc < 2) {
		std::cout << "Usage example: " << argv[0] << " 1-3000 random nubers separated by \" \"" << std::endl;
		return 1;
	}
	
	//soting with deque
	try{
		auto start = std::chrono::high_resolution_clock::now();
		PmergeMe dequed(argv, PmergeMe::DEQUE);
		for (size_t i = 0; i < dequed.getOriginalDeque().size(); ++i)
		{
			dequeBefore += std::to_string(dequed.getOriginalDeque()[i]);
			if (i != dequed.getOriginalDeque().size() - 1)
			{
				dequeBefore += ", ";
			}
		}
		containerSize = dequed.getOriginalDeque().size();
		
		dequed.makeSortingWithDeque();
		
		for (size_t i = 0; i <  dequed.getFinalDeque().size(); ++i)
		{
			dequeAfter += std::to_string(dequed.getFinalDeque()[i]);
			if (i != dequed.getFinalDeque().size() - 1)
			{
				dequeAfter += ", ";
			}
		}
		auto end = std::chrono::high_resolution_clock::now();	
		durationDeque = std::chrono::duration_cast<std::chrono::duration<double, std::micro>>(end - start);

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
		for (size_t i = 0; i < vectorized.getOriginalVector().size(); ++i)
		{
			vectorBefore += std::to_string(vectorized.getOriginalVector()[i]);
			if (i != vectorized.getOriginalVector().size() - 1)
			{
				vectorBefore += ", ";
			}
		}
		containerSize = vectorized.getOriginalVector().size();
		
		vectorized.makeSortingWithVector();
		
		for (size_t i = 0; i <  vectorized.getFinalVector().size(); ++i)
		{
			vectorAfter += std::to_string(vectorized.getFinalVector()[i]);
			if (i != vectorized.getFinalVector().size() - 1)
			{
				vectorAfter += ", ";
			}
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


	//check results

	if (vectorAfter != dequeAfter)
	{
		std::cerr << "Error: The results are not the same!" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "DequeBefore: " << dequeBefore << std::endl;
		std::cout << std::endl;
		std::cout << "DequeAfter: " << dequeAfter << std::endl;
		std::cout << std::endl;
		std::cout << "VectorBefore: " << vectorBefore << std::endl;
		std::cout << std::endl;
		std::cout << "VectorAfter: " << vectorAfter << std::endl;
		std::cout << std::endl;
		
	}


   std::cout << "Time to process a range of " << containerSize << " elements with std::deque: "
    << std::fixed << std::setprecision(6) << durationDeque.count() << " microseconds" << std::endl;
	

	std::cout << "Time to process a range of " << containerSize << " elements with std::vector: "
    << std::fixed << std::setprecision(6) << durationVector.count() << " microseconds" << std::endl;


	return 0;
}



