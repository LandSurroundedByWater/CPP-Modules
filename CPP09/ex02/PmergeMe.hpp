/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:23:55 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/24 12:53:02 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>

class PmergeMe
{
	public:

		enum ContainerType { LIST, VECTOR };
	
		PmergeMe(char **argv, ContainerType type);
		~PmergeMe();

		void makeSortingWithList();
		void makeSortingWithVector();

		std::list <unsigned int> getOriginalList() const;
		std::vector <unsigned int> getOriginalVector() const;

		std::list <unsigned int> getFinalList() const;
		std::vector <unsigned int> getFinalVector() const;
		
		std::list <std::pair<unsigned int, unsigned int>> getListPairs() const;
		std::vector <std::pair<unsigned int, unsigned int>> getVectorPairs() const;


		void mergeSortList(std::list<std::pair<unsigned int, unsigned int>>::iterator start,
							 std::list<std::pair<unsigned int, unsigned int>>::iterator mid,
							 std::list<std::pair<unsigned int, unsigned int>>::iterator end,
							 std::list<std::pair<unsigned int, unsigned int>>& tempList);
		
		void mergeSplitList(std::list<std::pair<unsigned int, unsigned int>>::iterator start,
							  std::list<std::pair<unsigned int, unsigned int>>::iterator end);

		void mergeSplitVector(unsigned int start, unsigned int end);
		void mergeSortVector( unsigned int  start, unsigned int  mid, unsigned int  end, std::vector <std::pair<unsigned int , unsigned int>>& tempVector);
		
		
		class NegativeNumberException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Error: Negative numbers are not allowed in unsigned list!";
			}
		};

		
		
	private:
		unsigned int listOrphan;
		unsigned int vectorOrphan;
		bool isOrphan;
		
		std::list <unsigned int> _originalList;
		std::vector <unsigned int> _originalVector;
		
		std::list <std::pair<unsigned int, unsigned int>> _listPairs;
		std::vector <std::pair<unsigned int, unsigned int>> _vectorPairs;
		

		std::list <unsigned int> _finalList;
		std::vector <unsigned int> _finalVector;
		
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void loadListFromArgs(char **argv);
		void loadVectorFromArgs(char **argv);
};
