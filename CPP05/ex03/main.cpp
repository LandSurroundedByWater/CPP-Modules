/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:42:37 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/29 15:03:21 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() 
{
	Intern freshmanIntern;
	AForm* shub;
	AForm* robo;
	AForm* pardon;
	AForm* unknown;
	Bureaucrat* bigBoss = nullptr;
	Bureaucrat* smallBoss = nullptr;

	try{
		bigBoss = new Bureaucrat("bigBoss", 6);
		smallBoss = new Bureaucrat("smallBoss", 34);

		try{
			shub = freshmanIntern.makeForm("Shrubbery Creation", "Cabin");
			std::cout << *shub << "\n";
			robo = freshmanIntern.makeForm("Robotomy Request", "Bender");
			std::cout << *robo << "\n";
			pardon = freshmanIntern.makeForm("Presidential Pardon", "Hibbelibob Beeblebub");
			std::cout << *pardon << "\n";
			unknown = freshmanIntern.makeForm("wrong form name", "Bob");
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
		
		std::cout << std::endl;
		std::cout << std::endl;
		
		try{
			shub->beSigned(*smallBoss);
			smallBoss->executeForm(*shub);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}

		std::cout << std::endl;
		std::cout << std::endl;
		try
		{
			robo->beSigned(*smallBoss);
			bigBoss->executeForm(*robo);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << std::endl;
		try{
			pardon->beSigned(*bigBoss);
			bigBoss->executeForm(*pardon);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "INCREASE BIGBOSS GRADE" << std::endl;
		std::cout << std::endl;
		
		bigBoss->increaseGrade();
		
		
		try{
			bigBoss->executeForm(*pardon);
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
	std::cout << "END" << std::endl;
	delete shub;
	delete robo;
	delete pardon;
	delete bigBoss;
	delete smallBoss;
	return 0;
}