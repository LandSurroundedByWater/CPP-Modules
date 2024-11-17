/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:37:47 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/17 10:37:50 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << " Defaut Bureaucrat " << _name << " has no real name yet." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name),
	_grade(grade)

{
	checkGrade(*this);
	std::cout << "Bureaucrat " << _name << " is working in office" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	
	this->_name = other._name;
	this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) 
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::setName(std::string value) {
	_name = value;
}

std::string Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::setGrade(int value) {
	_grade = value;
	checkGrade(*this);
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::increaseGrade()
{
	_grade--;
	checkGrade(*this);
}
			

void Bureaucrat::checkGrade(const Bureaucrat& check){
	if (check._grade < 1) {
		throw GradeTooHighException();
	} else if (check._grade > 150) {
		throw GradeTooLowException();
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& bgrat)
{
	out <<"Bureaucrat " << bgrat.getName() << ", grade " << bgrat.getGrade() << "." << std::endl;
	return out;
}
