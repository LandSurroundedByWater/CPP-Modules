/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/10 09:56:31 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
	std::cout << std::endl;
	std::cout <<  "Declaration of `boss` and `bigBossTimo` on the stack\n" << std::endl;

	try {
		
		Bureaucrat boss("Boss", 121);
		Bureaucrat bigBossTimo("Timo", 120);

		try {
			Form form1("Form1", 120, 3);
			
			std::cout << form1 << std::endl;

			form1.beSigned(boss);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
		
		try{
			Form form2("Form2", 120, 3);
			
			std::cout << form2 << std::endl;

			form2.beSigned(bigBossTimo);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Declaration of `boss2` and `bigBossTimo2` on the heap\n" << std::endl;

	Bureaucrat *boss2 = nullptr;
	Bureaucrat *bigBossTimo2 = nullptr;

	try {
		boss2 = new Bureaucrat("Boss", 100);
		bigBossTimo2 = new Bureaucrat("Timo", 2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Form form3("Form3", 120, 3);
		
		std::cout << form3 << std::endl;
		
		form3.beSigned(*bigBossTimo2);
		form3.beSigned(*bigBossTimo2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "END OF TESTS" << std::endl;
	delete boss2;
	delete bigBossTimo2;
}

