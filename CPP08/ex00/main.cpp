/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/07 11:09:19 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <deque>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
	std::deque<int> deq = {11, 12, 13, 14, 15};

    try
    {
		std::cout << "Trying to find 3 from vec\n";
        std::vector<int>::iterator it = easyfind(vec, 3);  //give type to compiler
        std::cout << "Found: " << *it << '\n';
		std::cout << "Trying to find 10 from vec\n";
        it = easyfind(vec, 10);
        std::cout << "Found: " << *it << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
	
	try
	{
		std::cout << "Add 10 to end of vec\n";
		vec.push_back(10);
		std::cout << "Trying to find 10 from vec\n";
		auto it = easyfind(vec, 10);			//compiler deduces type, takes a little bit more time
		std::cout << "Found: " << *it << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	try{
		std::cout << "Trying to find 13 from deq\n";
		auto it = easyfind(deq, 13);
		std::cout << "Found: " << *it << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	try{
		std::cout << "Trying to find 20 from deq\n";
		auto it = easyfind(deq, 20);
		std::cout << "Found: " << *it << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	try{
		std::cout << "Add 20 to front of deq\n";
		deq.push_front(20);
		std::cout << "Trying to find 20 from deq\n";
		auto it = easyfind(deq, 20);
		std::cout << "Found: " << *it << '\n';
	}
	catch(const std::exception& e){
		std::cerr << "Exception: " << e.what() << '\n';
	}
	
	const std::vector<int> vecc = {1, 2, 3, 4, 5};
	try
    {
		std::cout << "Trying to find 3 from vec\n";
        std::vector<int>::iterator it = easyfind(vec, 3);  //give type to compiler
        std::cout << "Found: " << *it << '\n';
		std::cout << "Trying to find 10 from vec\n";
        it = easyfind(vec, 10);
        std::cout << "Found: " << *it << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return 0;
}