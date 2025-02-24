/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:29:27 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/18 13:28:07 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>


RPN::RPN() {}

RPN::RPN(const std::string &inputString)
{
	loadStackFromString(inputString);
}
	

RPN::RPN(const RPN &other)
{
	_inputStack = other._inputStack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_inputStack = other._inputStack;
	}
	return *this;
}

RPN::~RPN() {}

bool isValidRPN(const std::string& input) {
    return std::all_of(input.begin(), input.end(), [](char c) {
        return (c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '-' || c == '*' || c == '/';
    });
}

bool isValidChar(char c) {
    return (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::loadStackFromString(const std::string &inputString)
{

	for (int i = inputString.length() - 1; i >= 0; --i)
	{
		char c = inputString[i];
		if (c == ' ')
			continue;
		else if (!isValidChar(c))
			throw std::invalid_argument("Error");
		else
			_inputStack.push(std::string(1, c));
	}
}
bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

void RPN::executeRPN(){
	int temp;
	int temp2;
	while(!_inputStack.empty())
	{
		std::string next = _inputStack.top();
		_inputStack.pop();
		if (!isOperator(next))
			_executionStack.push(std::stoi(next));
		else {
			if (_executionStack.size() < 2)
				throw std::invalid_argument("Error: cannot calculate " + next + ", not enough numbers.");
			temp = _executionStack.top();
			_executionStack.pop();
			temp2 = _executionStack.top();
			_executionStack.pop();
			if (next == "+")
				_executionStack.push(temp2 + temp);
			else if (next == "-")
				_executionStack.push(temp2 - temp);
			else if (next == "*")
				_executionStack.push(temp2 * temp);
			else if (next == "/")
			{
				if (temp == 0)
					throw std::invalid_argument("Error: Calculation failed. Division by zero is undefined.");
				else
					_executionStack.push(temp2 / temp);
			}
		}
		
	}
	if (_executionStack.size() > 1)
		throw std::invalid_argument("Error: cannot calculate, too many numbers.");
	else
		std::cout << _executionStack.top() << std::endl;
}