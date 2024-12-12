/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:39:42 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/12 09:39:06 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeReguiredToExecute(1)
{
	_signedBy = "Unsigned";
}

AForm::AForm(std::string name, int grade, int gradeRequired) :
	_name(name),
	_isSigned(false),
	_gradeToSign(grade),
	_gradeReguiredToExecute(gradeRequired) {
		_signedBy = "Unsigned";
		checkGrade(*this);
	}

AForm::AForm(const AForm& other): 
	_name(other._name),
	_isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), 
	_gradeReguiredToExecute(other._gradeReguiredToExecute) {
		_signedBy = other._signedBy;
	}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
		this->_signedBy = other._signedBy;
	}
	return *this;
}

AForm::~AForm() {}


//----------------GETTERS AND SETTER----------------

std::string AForm::getName() const {return _name;}

bool AForm::getIsSigned() const {return _isSigned;}

int AForm::getGradeToSign() const {return _gradeToSign;}

int AForm::getGradeRequidedToExecute() const {return _gradeReguiredToExecute;}

std::string AForm::getSignedBy() const {return _signedBy;}

void AForm::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}
void AForm::setSignedBy(std::string signedBy)
{
	_signedBy = signedBy;
}
//----------------------MEMBER FUNCTIONS------------------------

void AForm::beSigned(Bureaucrat& bcrat)
{
	if (!_isSigned) 
	{
		if (bcrat.getGrade() <= getGradeToSign()) 
		{
			setIsSigned(true);
			_signedBy = bcrat.getName();
		}
		bcrat.signForm(_isSigned, getName());
	}
	else {
		std::cout << bcrat.getName() << " cannot sign " << _name << " because the form is already signed" << std::endl;
	}
}

void AForm::checkGrade(const AForm& check)
{
	if (check._gradeToSign < 1 || check._gradeReguiredToExecute < 1) {
		throw GradeTooHighException();
	} else if (check._gradeToSign > 150 || check._gradeReguiredToExecute > 150) {
		throw GradeTooLowException();
	}
}

//-------------------EXCEPTIONS--------------------

const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return "Form is not signed";
}

const char* AForm::FormAlreadySignedException::what() const noexcept {
	return "Form is already signed";
}


//-----------------STREAM OPERATOR

std::ostream &operator<<(std::ostream &out, const AForm& form)
{
	std::string sign = "false";
	if (form.getIsSigned())
	{
		sign = "true";
	}
	out <<"Form name: " << form.getName() << std::endl << "Form grade to sign: " << form.getGradeToSign() << 
	std::endl << "Form is signed: " << sign << std::endl <<  "Form required grade to execute: " << form.getGradeRequidedToExecute() << std::endl;
	return out;
}


