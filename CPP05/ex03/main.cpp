/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/26 11:01:29 by tsaari           ###   ########.fr       */
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
	try{
		bigBoss = new Bureaucrat("Timo", 6);
		smallBoss = new Bureaucrat("Jack", 34);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		     delete shub;
        delete robo;
        delete pardon;
        return 1;
	}
	
	try{
		shub->beSigned(*smallBoss);
		shub->execute(*smallBoss);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	try
	{
		robo->beSigned(*smallBoss);
		robo->execute(*bigBoss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try{
		pardon->beSigned(*bigBoss);
		pardon->execute(*bigBoss);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	
	bigBoss->increaseGrade();
		
	try{
		pardon->execute(*bigBoss);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "END" << std::endl;
	delete shub;
	delete robo;
	delete pardon;
	return 0;
}

