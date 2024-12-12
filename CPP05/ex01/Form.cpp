/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:38:08 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/12 09:38:03 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeReguiredToExecute(1)
{
	_signedBy = "Unsigned";
}

Form::Form(std::string name, int grade, int gradeRequired) :
	_name(name),
	_isSigned(false),
	_gradeToSign(grade),
	_gradeReguiredToExecute(gradeRequired) {
		_signedBy = "Unsigned";
		checkGrade(*this);
	}

Form::Form(const Form& other)
	: _name(other._name),
	  _isSigned(other._isSigned), 
	  _gradeToSign(other._gradeToSign), 
	  _gradeReguiredToExecute(other._gradeReguiredToExecute) {
			_signedBy = other._signedBy;
	  }

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
		this->_signedBy = other._signedBy;
	}
	return *this;
}

Form::~Form() {}

//----------------GETTERS AND SETTER----------------

std::string Form::getName() const {return _name;}

bool Form::getIsSigned() const {return _isSigned;}

int Form::getGradeToSign() const {return _gradeToSign;}

int Form::getGradeRequidedToExecute() const {return _gradeReguiredToExecute;}

std::string Form::getSignedBy() const {return _signedBy;}

void Form::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}

//-------------------MEMBER FUNCTIONS---------------------------

void Form::beSigned(Bureaucrat& bcrat)
{
	if (!_isSigned) {
		if (bcrat.getGrade() <= getGradeToSign()) {
			setIsSigned(true);
			_signedBy = bcrat.getName();
			bcrat.signForm(_isSigned, getName());
		}
		else 
		{
			bcrat.signForm(_isSigned, getName());
			throw GradeTooLowException();
		}
	}
	else {
		std::cout << bcrat.getName() << " cannot sign " << _name << " because the form is already signed" << std::endl;
	}
}
void Form::checkGrade(const Form& check){
	if (check._gradeToSign < 1 || check._gradeReguiredToExecute < 1) {
		throw GradeTooHighException();
	} else if (check._gradeToSign > 150 || check._gradeReguiredToExecute > 150) {
		throw GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form& form)
{
	std::string sign = "false";
	if (form.getIsSigned())
	{
		sign = "true";
	}
	out <<"Form name: " << form.getName() << std::endl << "Form grade: " << form.getGradeToSign() << 
	std::endl << "Form is signed: " << sign << std::endl <<  "Form required grade: " << form.getGradeRequidedToExecute() << std::endl;
	return out;
}
