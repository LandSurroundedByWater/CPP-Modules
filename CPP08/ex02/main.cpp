/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:19:09 by tsaari            #+#    #+#             */
/*   Updated: 2025/01/31 09:22:58 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
	
	MutantStack<int> mstack;
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
	//[...]
	mstack.push(0);

	std::cout << "Iterate and print all: ";
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		if (++it != ite)
			std::cout << *it << ", ";
		else
			std::cout << *it << std::endl;
	}
	std::stack<int> s(mstack);



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
	//[...]
	lst.push_back(0);

	std::cout << "Iterate and print all: ";
	
	std::list<int>::iterator itlst = lst.begin();
	std::list<int>::iterator itelst = lst.end();

	while (itlst != itelst)
	{
		if (++itlst != itelst)
			std::cout << *itlst << ", ";
		else
			std::cout << *itlst << std::endl;
	}

	
	return 0;
		
}