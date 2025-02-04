/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:28:59 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/03 08:42:43 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <string>

class RPN
{
	public:
		RPN(const std::string& inputString);
		~RPN();
		
		void executeRPN();
	
	private:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		
		std::stack<std::string> _inputStack;
		std::stack<int> _executionStack;
		void loadStackFromString(const std::string& inputString);
};