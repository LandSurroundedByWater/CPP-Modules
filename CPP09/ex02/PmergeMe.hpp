/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:23:55 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/04 08:28:28 by tsaari           ###   ########.fr       */
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

		std::list <int> getOriginalList() const;
		std::vector <int> getOriginalVector() const;

		std::list <int> getFinalList() const;
		std::vector <int> getFinalVector() const;
		
		std::list <std::pair<int, int>> getListPairs() const;
		std::vector <std::pair<int, int>> getVectorPairs() const;
		
		
		class NegativeNumberException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Error: Negative numbers are not allowed in unsigned list!";
			}
		};

		
		
	private:
		int listOrphan;
		int vectorOrphan;
		
		std::list <int> _originalList;
		std::vector <int> _originalVector;
		
		std::list <std::pair<int, int>> _listPairs;
		std::vector <std::pair<int, int>> _vectorPairs;

		std::list <int> _finalList;
		std::vector <int> _finalVector;
		
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void loadListFromArgs(char **argv);
		void loadVectorFromArgs(char **argv);
};
