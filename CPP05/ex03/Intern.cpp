/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:36:57 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/17 10:36:59 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()  {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

			
AForm* Intern::makeForm(std::string formToCreate, std::string target) {

	std::string forms[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	int i = 0;
	for(std::string names : forms) {
		if (formToCreate == names) {
			break ;
		}
		i++;
	}
	switch (i) {
		case 0:
		{
			std::cout << "Intern creates ShrubberyCreationForm " << target << std::endl;
			return new ShrubberyCreationForm(target);
			
		}
		case 1:
		{
			std::cout << "Intern creates RobotomyRequestForm " << target << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 2:
		{
			std::cout << "Intern creates PresidentialPardonForm " << target << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
		{
			std::cerr << "Error: Form name '" << formToCreate << "' is invalid." << std::endl;
            return nullptr;;
		}
	}
}

