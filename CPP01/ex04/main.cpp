/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:57:28 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/11 14:50:21 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <cstring>


void replaceAll(std::string& line, const std::string& s1, const std::string& s2) 
{
	std::string result;
	size_t pos = 0;

	if (s1.length() < 1)
		return;
	while (true) 
	{
		size_t found = line.find(s1, pos);
		if (found == std::string::npos) 
		{
			result.append(line.substr(pos));
			break;
		}
		result.append(line.substr(pos, found - pos));
		result.append(s2);
		pos = found + s1.length();
	}
	line = result;
}

void readAndReplaceFile(const std::string& sourceFile, std::string& destFile, std::string& s1, std::string& s2) {
	std::ifstream inputFile(sourceFile); 
	if (!inputFile) 
	{ 
		std::cerr << "Failed to open the source file: " << sourceFile << std::endl;
		std::cerr << "Error: " << strerror(errno) << std::endl;
		return;
	}
	std::ofstream outputFile(destFile);
	if (!outputFile) 
	{
		std::cerr << "Failed to open the destination file: " << destFile << std::endl;
		std::cerr << "Error: " << strerror(errno) << std::endl;
		return;
	}
	std::string line;
	while (std::getline(inputFile, line)) 
	{
		replaceAll(line, s1, s2);
		if (s1 == "\n") 
		{
			outputFile << line;
		} 
		else 
		{
			outputFile << line << std::endl;
		}
	}
	inputFile.close();
	outputFile.close();
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		std::cout << "Invalid number of arguments." << std::endl;
	else
	{
		std::string sourceFilename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		std::string destFilename = sourceFilename + ".replace";
		readAndReplaceFile(argv[1], destFilename, s1, s2);
	}
	return (0);
}