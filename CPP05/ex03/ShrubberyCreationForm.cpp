/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:36:02 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/17 18:37:02 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {  
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


// Getters and Setters

void ShrubberyCreationForm::setTarget(std::string target) {_target = target;}

const std::string ShrubberyCreationForm::getTarget() const {return _target;}

// Methods

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeRequided()){
		throw AForm::GradeTooLowException();
	}
	if (!this->getIsSigned()){
		throw AForm::FormNotSignedException();	
	}

	std::ofstream ofs(_target + "_shrubbery");
	if (!ofs) {
		throw std::runtime_error("Failed to open output file.");
	}
	ofs << "     @@         @@          @@         @@           @        @@@ @   \n"
		<< "    @ @@@      @ @ @       @ @@@      @ @@         @ @      @ @@@ @  \n"
		<< "   @@ /@@     @@ |@@      @@ /@@@    @@ /@@       @ /@@    @@@ /@@ @ \n"
		<< "   @@@|@@@    @@@|@@@     @@ |@ @    @@ |@@      @ @|@ @   @ @@|@@@  \n"
		<< "   @@ |/@     @@ |/@      @@ |/@     @@ |/@       @ / @     @@ |/@   \n"
		<< "     @|@        @|@         @|@        @|@         @|@        @|@    \n"
		<< "      |          |           |          |           |          |     \n"
		<< "      |          |           |          |           |          |     \n";

	ofs.close();
	std::cout << "Shrubbery creation complete at target: " << _target << std::endl;
	std::cout << "File created: " << _target << "_shrubbery" << std::endl;
	std::cout << "Form signed by: " << this->getSignedBy() << std::endl;
	std::cout << "Executor: " << executor.getName() << std::endl;

}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form) {
    // Call the base class operator<<
    out << static_cast<const AForm&>(form);
    // Append the derived class-specific attribute
    out << "Target: " << form.getTarget() << std::endl;
    return out;
}