/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/07 10:51:24 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>
#include <vector>



int main()
{
	
	MutantStack<int> mstack;
	//MutantStack<int, std::vector<int>> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "remove last one" << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(0);

	std::cout << "Iterate and print all: ";
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	//MutantStack<int, std::vector<int>>::const_iterator it = mstack.begin();
	//MutantStack<int, std::vector<int>>::const_iterator ite = mstack.end();
	
	while (it != ite)
	{
		std::cout << *it;

		if (++it != ite)
			std::cout << ", ";
	}
	
	std::cout << std::endl;
	//--------------------------------------------------------------

	std::cout << std::endl;
	std::cout << "Testing with std::list" << std::endl;
	
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "top: " << lst.back() << std::endl;
	std::cout << "remove last one" << std::endl;
	lst.pop_back();
	std::cout << "size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	std::cout << "top: " << lst.back() << std::endl;
	std::cout << "size: " << lst.size() << std::endl;
	lst.push_back(0);

	std::cout << "Iterate and print all: ";
	
	std::list<int>::iterator itlst = lst.begin();
	std::list<int>::iterator itelst = lst.end();

	
	while (itlst != itelst)
	{
		std::cout << *itlst;
		
		if (++itlst != itelst)
			std::cout << ", ";
	}
	std::cout << std::endl;


	//--------------------------------------------------------------


	std::cout << std::endl;
	std::cout << "Testing with const stack and const iterators" << std::endl;
	
	const MutantStack<int> cmstack(mstack);
	//const MutantStack<int, std::vector<int>> cmstack(mstack);
	
	
	MutantStack<int>::const_iterator cit = cmstack.begin();
	MutantStack<int>::const_iterator cite = cmstack.end();

	
	//MutantStack<int, std::vector<int>>::const_iterator cit = mstack.begin();
	//MutantStack<int, std::vector<int>>::const_iterator cite = mstack.end();
	
	
	std::cout << "Iterate and print all: ";
	while (cit != cite)
	{
		std::cout << *cit;
		if (++cit != cite)
        	std::cout << ", ";
	}
	std::cout << std::endl;

	return 0;
		
}
