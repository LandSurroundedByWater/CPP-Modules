/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:36:02 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/10 09:58:46 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {  
		this->_target = other._target;
		this->setIsSigned(other.getIsSigned());
		this->setSignedBy(other.getSignedBy());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


//-----------------Getters and Setters----------------[]

void ShrubberyCreationForm::setTarget(std::string target) {_target = target;}

const std::string ShrubberyCreationForm::getTarget() const {return _target;}

//-----------------MEMBER FUNCTIONS--------------------

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned()){
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeRequidedToExecute()) {
		throw AForm::GradeTooLowException();
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
	out << static_cast<const AForm&>(form);
	out << "Target: " << form.getTarget() << std::endl;
	return out;
}
