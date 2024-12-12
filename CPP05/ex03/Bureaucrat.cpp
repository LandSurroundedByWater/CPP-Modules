/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:36:57 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/04 12:39:25 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//----CONSTRUCTORS AND DESTRUCTORS

//- default
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << " Defaut Bureaucrat " << _name << " has no real name yet." << std::endl;
}


//-	parameters
Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name),
	_grade(grade)
{
	checkGrade(*this);
	std::cout << "Bureaucrat " << _name << " is working in office" << std::endl;
}

//-	copy
Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other.getName()), 
	_grade(other.getGrade()) {
		checkGrade(*this);
	}

//- copyassign opertor
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) 
	{
		this->_grade = other._grade;
	}
	return *this;
}


//- destructor
Bureaucrat::~Bureaucrat() {}

//----------GETTERS-------------

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

//-------------MEMBER FUNCTIONNS---------

void Bureaucrat::increaseGrade()
{
	_grade--;
	checkGrade(*this);
}

void Bureaucrat::decreaseGrade()
{
	_grade++;
	checkGrade(*this);
}
			

void Bureaucrat::checkGrade(const Bureaucrat& check){
	if (check._grade < 1) {
		throw GradeTooHighException();
	} else if (check._grade > 150) {
		throw GradeTooLowException();
	}
}

void Bureaucrat::signForm(bool sign, std::string formName) {

	if (sign) {
		std::cout << getName() << " signs " << formName << std::endl;
	}
	else {
		std::cout << getName() << " couldn't sign form " << formName << " because grade is too low" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << " signed by " << form.getSignedBy() <<std::endl;
	}
	catch (const std::exception &e) {
		std::cout << getName() << " couldn't execute form " << form.getName() << " because: ";
		std::cerr << e.what() << '\n';
	}
}

//-----------------EXCEPTIONS------------------

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

//---------------STREAM OPERATOR---------------

std::ostream &operator<<(std::ostream &out, const Bureaucrat& bgrat)
{
	out <<"Bureaucrat " << bgrat.getName() << ", grade " << bgrat.getGrade() << "." << std::endl;
	return out;
}