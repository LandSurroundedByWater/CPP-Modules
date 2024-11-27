/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:39:42 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/27 11:14:44 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("DefaultForm"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeReguiredToExecute(1) {
		_signedBy = "No one";
	}

AForm::AForm(std::string name, bool isSigned, int grade, int executeGrade) :
	_name(name),
	_isSigned(isSigned),
	_gradeToSign(grade),
	_gradeReguiredToExecute(executeGrade) {
		_signedBy = "No one";
		checkGrade(*this);
	}

AForm::AForm(const AForm& other) {
	this->_name = other._name;
	this->_isSigned = other._isSigned;
	this->_gradeToSign = other._gradeToSign;
	this->_gradeReguiredToExecute = other._gradeReguiredToExecute;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_isSigned = other._isSigned;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeReguiredToExecute = other._gradeReguiredToExecute;
	}
	return *this;
}

AForm::~AForm() {}

void AForm::setName(std::string value) {_name = value;}

std::string AForm::getName() const {return _name;}

void AForm::setIsSigned(bool value) {_isSigned = value;}

bool AForm::getIsSigned() const {return _isSigned;}

void AForm::setSignedBy(std::string value) {_signedBy = value;}

std::string AForm::getSignedBy() const {return _signedBy;}

void AForm::setGrade(int value) {
	_gradeToSign = value;
	checkGrade(*this);
}

int AForm::getGrade() const {return _gradeToSign;}

void AForm::setGradeRequided(int value) {
_gradeReguiredToExecute = value;
checkGrade(*this);
}

int AForm::getGradeRequided() const {return _gradeReguiredToExecute;}

//----------------------------------------------

void AForm::beSigned(Bureaucrat& bgrat) {
	if (!_isSigned) {
		if (bgrat.signForm(getGrade(), getName())) {
			setIsSigned(true);
			_signedBy = bgrat.getName();
		}
	}
	else {
		std::cout << bgrat.getName() << " cannot sign " << _name << " because the form is already signed" << std::endl;
	}
}

void AForm::checkGrade(const AForm& check){
	if (check._gradeToSign < 1 || check._gradeReguiredToExecute < 1) {
		throw GradeTooHighException();
	} else if (check._gradeToSign > 150 || check._gradeReguiredToExecute > 150) {
		throw GradeTooLowException();
	}
}

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

std::ostream &operator<<(std::ostream &out, const AForm& form)
{
	std::string sign = "false";
	if (form.getIsSigned())
	{
		sign = "true";
	}
	out <<"AForm name: " << form.getName() << std::endl << "AForm grade: " << form.getGrade() << 
	std::endl << "AForm is signed: " << sign << std::endl <<  "AForm required grade: " << form.getGradeRequided() << std::endl;
	return out;
}


