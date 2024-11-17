/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/17 20:48:37 by tsaari           ###   ########.fr       */
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

	shub = freshmanIntern.makeForm("Shrubbery Creation", "Cabin");
	std::cout << *shub << "\n";
	robo = freshmanIntern.makeForm("Robotomy Request", "Bender");
	std::cout << *robo << "\n";
	pardon = freshmanIntern.makeForm("Presidential Pardon", "Hibbelibob Beeblebub");
	std::cout << *pardon << "\n";
	unknown = freshmanIntern.makeForm("wrong form name", "Bob");
	if (unknown != nullptr)
		std::cout << *unknown << "\n";
	
	Bureaucrat bigBoss("Timo", 6);
	Bureaucrat smallBoss("Jack", 34);

	try{
		shub->signForm(smallBoss);
		shub->execute(smallBoss);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	try
	{
		robo->signForm(smallBoss);
		robo->execute(bigBoss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try{
		pardon->signForm(bigBoss);
		pardon->execute(bigBoss);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	
	bigBoss.increaseGrade();
		
	try{
		pardon->execute(bigBoss);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	delete shub;
	delete robo;
	delete pardon;
	delete unknown;
	return 0;
}
