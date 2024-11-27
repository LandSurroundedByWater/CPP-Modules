/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/27 12:16:57 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
	std::cout << std::endl;
	std::cout <<  "Declaration of `boss` and `bigBossTimo` on the stack\n" << std::endl;

	try {
		
		Bureaucrat boss("Boss", 100);
		Bureaucrat bigBossTimo("Timo", 2);

		try {
			Form form0;
			Form form1("Form1", false, 120, 3);

			std::cout << form1 << std::endl;
			std::cout << form0 << std::endl;

			form0.setName("Form0");
			form0.setGrade(20);
			form0.setGradeRequided(1);
			form0.setIsSigned(false);
			std::cout << form0 << std::endl;

			form0.beSigned(boss);
			form1.beSigned(bigBossTimo);
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
		Form form3;
		Form form4("Form1", false, 120, 3);
		std::cout << form3 << std::endl;
		std::cout << form4 << std::endl;
		form3.setName("Form0");
		form3.setGrade(20);
		form3.setGradeRequided(1);
		form3.setIsSigned(false);
		std::cout << form3 << std::endl;

		form3.beSigned(*boss2);
		form4.beSigned(*bigBossTimo2);
		form4.beSigned(*bigBossTimo2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "END OF TESTS" << std::endl;
	delete boss2;
	delete bigBossTimo2;
}

