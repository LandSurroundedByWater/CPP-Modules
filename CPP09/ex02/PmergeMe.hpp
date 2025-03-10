/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:23:55 by tsaari            #+#    #+#             */
/*   Updated: 2025/03/05 13:17:37 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <string>

class PmergeMe
{
	public:

		enum ContainerType { DEQUE, VECTOR };
	
		PmergeMe(char **argv, ContainerType type);
		~PmergeMe();
		
		void makeSortingWithVector();
		void makeSortingWithDeque();

		std::vector <int> getOriginalVector() const;
		std::deque <int> getOriginalDeque() const;

		std::vector <int> getFinalVector() const;
		std::deque <int> getFinalDeque() const;
		
		std::vector <std::pair<int, int>> getVectorPairs() const;
		std::deque <std::pair<int, int>> getDequePairs() const;

		void mergeSplitDeque(int start, int end);
		void mergeSortDeque( int  start, int mid, int end, std::deque <std::pair<int, int>>& tempDeque);

		void mergeSplitVector(int start, int end);
		void mergeSortVector(int  start, int mid, int end, std::vector <std::pair<int, int>>& tempVector);
		void insertUsingJacobsthalDeque();
		void insertUsingJacobsthalVector();
		
		class NegativeNumberException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Error: Negative numbers are not allowed in unsigned list!";
			}
		};

		
		
	private:

		int dequeOrphan;
		int vectorOrphan;
		bool isOrphan;
		

		std::vector <int> _originalVector;
		std::deque <int> _originalDeque;
		

		std::vector <std::pair<int, int>> _vectorPairs;
		std::deque <std::pair<int, int>> _dequePairs;

		std::vector <int> _finalVector;
		std::deque <int> _finalDeque;
		
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void loadVectorFromArgs(char **argv);
		void loadDequeFromArgs(char **argv);
};
