/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/17 18:50:18 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() 
{


// TESTS FOR SHRUBBERY CREATION FORM

	std::cout << std::endl;
	std::cout << "TESTS FOR SHRUBBERY CREATION FORM"<<std::endl;
	std::cout << std::endl;
	try {
		
		Bureaucrat bigBoss("Timo", 2);
		Bureaucrat smallBoss("Jack", 146);
		
		std::cout << smallBoss.getName() << ", grade " << smallBoss.getGrade() << ". " << std::endl;
		try {
			//create a form
			ShrubberyCreationForm form1("Home");


			//sign the form
			std::cout << form1 << std::endl;
			try{
				form1.signForm(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			try {
				smallBoss.increaseGrade();
				std::cout << smallBoss << std::endl;
				form1.signForm(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			try {
				smallBoss.increaseGrade();
				std::cout << smallBoss << std::endl;
				form1.signForm(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}

			// Execute the form
			try {
				form1.execute(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			try {
				form1.execute(bigBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}

// TESTS FOR ROBOTOMY REQUEST FORM
	
	std::cout << std::endl;
	std::cout << "TESTS FOR ROBOTOMY REQUEST FORM"<<std::endl;
	std::cout << std::endl;
	try {
		
		Bureaucrat bigBoss("Timo", 60);
		Bureaucrat smallBoss("Jack", 146);
		
		std::cout << smallBoss.getName() << ", grade " << smallBoss.getGrade() << ". " << std::endl;
		try {
			std::cout << std::endl;		
			std::cout << "CREATE A FORM" << std::endl;
			std::cout << std::endl;		
			RobotomyRequestForm form2("Roboticotico");
			std::cout << form2 << std::endl;
			std::cout << std::endl;		


			std::cout << "SIGN THE FORM" << std::endl;
			try{
				form2.signForm(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			try {
				smallBoss.increaseGrade();
				std::cout << smallBoss << std::endl;
				form2.signForm(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			try {
				smallBoss.increaseGrade();
				std::cout << smallBoss << std::endl;
				form2.signForm(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			std::cout << std::endl;		
			std::cout << "SMALLBOSS TRY TO EXECUTE" << std::endl;
			std::cout << std::endl;				
			try {
				form2.execute(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			std::cout << std::endl;		
			std::cout << "BIGBOSS TRY TO EXECUTE" << std::endl;
			std::cout << std::endl;		
			try {
				form2.execute(bigBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			std::cout << std::endl;		
			std::cout << "INCREASE GRADE OF SMALLBOSS" << std::endl;
			std::cout << std::endl;		
			smallBoss.setGrade(72);
			std::cout << smallBoss << std::endl;

			
			std::cout << "SIGN AGAIN" << std::endl;
			form2.signForm(smallBoss);

			std::cout << "EXECUTE AGAIN" << std::endl;	
			std::cout << std::endl;	
				
			try {
				form2.execute(bigBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			try {
				form2.execute(bigBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			std::cout << "increase the grade of the bigBoss" << std::endl;
			bigBoss.setGrade(45);
			
			try {
				form2.execute(bigBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}

	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
	

// TESTS FOR PRESIDENTIAL PARDON FORM


	std::cout << std::endl;
	std::cout << "TESTS FOR PRESIDENTIAL PARDON FORM"<<std::endl;
	std::cout << std::endl;
	try {
		
		Bureaucrat bigBoss("Timo", 6);
		Bureaucrat smallBoss("Jack", 146);
		
		std::cout << smallBoss.getName() << ", grade " << smallBoss.getGrade() << ". " << std::endl;
		try {
			
			std::cout << std::endl;		
			std::cout << "CREATE A FORM" << std::endl;
			std::cout << std::endl;		
			PresidentialPardonForm form2("Hibbelibub Beeblebob");
			std::cout << std::endl;		
			std::cout << form2 << std::endl;

			std::cout << std::endl;	
			
			//icrease the grade of the smallboss
			
			smallBoss.setGrade(25);
			
			std::cout << "SIGN THE FORM" << std::endl;
				
			form2.signForm(smallBoss);
	
			
			try {
				form2.execute(bigBoss);
			}
			catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			}

			try {
				bigBoss.increaseGrade(); //because bigBoss Timo's grade is 6, and 5 needed
				form2.execute(bigBoss);
			}
			catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			}
	
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}

		
}

