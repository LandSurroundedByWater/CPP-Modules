/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:48 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/29 14:53:11 by tsaari           ###   ########.fr       */
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

	std::cout << "\033[1;31m" << std::endl;
	std::cout << "TESTS FOR SHRUBBERY CREATION FORM"<<std::endl;
	std::cout << "\033[0m" << std::endl;
	try {
		
		Bureaucrat bigBoss("bigBoss", 2);
		Bureaucrat smallBoss("smallBoss", 146);
	
		std::cout << smallBoss.getName() << ", grade " << smallBoss.getGrade() << ". " << std::endl;
		try {
			std::cout << std::endl;		
			std::cout << "CREATE FORM" << std::endl;
			ShrubberyCreationForm form1("Home");
			std::cout << form1 << std::endl;
			
			std::cout << std::endl;		
			std::cout << "SIGN FORM" << std::endl;
			//cannot sign
			try{
				form1.beSigned(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			//increases and signs
			try {
				smallBoss.increaseGrade();
				std::cout << smallBoss << std::endl;
				form1.beSigned(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			//tries to sign allready signed form
			try {
				form1.beSigned(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}

			std::cout << std::endl;
			std::cout << "EXECUTE  FORM" << std::endl;
			//cannot execute
			try {
				smallBoss.executeForm(form1);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			try {
				bigBoss.executeForm(form1);
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
	}

// TESTS FOR ROBOTOMY REQUEST FORM
	
	std::cout <<  "\033[1;31m" << std::endl;
	std::cout << "TESTS FOR ROBOTOMY REQUEST FORM"<<std::endl;
	std::cout << "\033[0m" << std::endl;
	try {
		
		Bureaucrat bigBoss("bigBoss", 60);
		Bureaucrat smallBoss("smallBoss", 146);
		
		std::cout << std::endl;		
		std::cout << "CREATE A FORM" << std::endl;
		try {
			RobotomyRequestForm form2("Roboticotico");
			std::cout << form2 << std::endl;

			std::cout << std::endl;		
			std::cout << "SIGN THE FORM" << std::endl;
			try{
				form2.beSigned(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			std::cout << std::endl;	
			std::cout << "INCREASE AND SIGN AGAIN" << std::endl;
			try {
				smallBoss.increaseGrade();
				std::cout << smallBoss << std::endl;
				form2.beSigned(smallBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			std::cout << std::endl;		
			std::cout << "SMALLBOSS CANNOT SIGN, SO BIGBOSS HELPS" << std::endl;
			
			try {
				form2.beSigned(bigBoss);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			std::cout << std::endl;		
			std::cout << "SMALLBOSS TRIES TO EXECUTE" << std::endl;		
				
			try {
				smallBoss.executeForm(form2);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}

			
			std::cout << std::endl;		
			std::cout << "BIGBOSS TRIES TO EXECUTE" << std::endl;		
			try {
				bigBoss.executeForm(form2);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
			
			std::cout << std::endl;	
			std::cout << "INGREASE THE GRADE OF BIGBOSS" << std::endl;
		
			while (bigBoss.getGrade() > form2.getGradeRequidedToExecute())
				bigBoss.increaseGrade();
		
			try {
				bigBoss.executeForm(form2);
			}
			catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			}
		} //IF FORM IS NOT CREATED
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}

	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	

// TESTS FOR PRESIDENTIAL PARDON FORM

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;31m" << std::endl;
	std::cout << "TESTS FOR PRESIDENTIAL PARDON FORM"<<std::endl;
	std::cout << "\033[0m" << std::endl;
	try {
		
		Bureaucrat bigBoss("bigBoss", 6);
		Bureaucrat smallBoss("smallBoss", 146);
		
		std::cout << smallBoss.getName() << ", grade " << smallBoss.getGrade() << ". " << std::endl;
		try {
			
			std::cout << std::endl;		
			std::cout << "CREATE A FORM" << std::endl;
		
			PresidentialPardonForm form2("Hibbelibub Beeblebob");
			std::cout << form2 << std::endl;

			std::cout << std::endl;	
			std::cout << "SIGN THE FORM" << std::endl;
			try
			{
				form2.beSigned(smallBoss); //cannot do it 
			}
			catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			}
			std::cout << std::endl;	
			std::cout << "INCREASE GRADE OF SMALLBOSS" << std::endl;

			while (smallBoss.getGrade() > form2.getGradeToSign())
				smallBoss.increaseGrade();

			try
			{
				form2.beSigned(smallBoss);
			}
			catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			}

			
			std::cout << std::endl;	
			std::cout << "EXECUTE" << std::endl;
			
			try {
				bigBoss.executeForm(form2);
			}
			catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			}

			
			std::cout << std::endl;	
			std::cout << "INCREASE GRADE OF BIGBOSS" << std::endl;
			try {
				bigBoss.increaseGrade(); //because bigBoss Timo's grade is 6, and 5 needed
				bigBoss.executeForm(form2);
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
	}
	std::cout << std::endl;		
	std::cout << "THE END" << std::endl;
		
}

