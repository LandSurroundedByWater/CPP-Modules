/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:38:08 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/17 10:38:11 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("DefaultForm"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeReguiredToExecute(1) {
		_signedBy = "No one";
	}

Form::Form(std::string name, bool isSigned, int grade, int gradeRequired) :
	_name(name),
	_isSigned(isSigned),
	_gradeToSign(grade),
	_gradeReguiredToExecute(gradeRequired) {
		_signedBy = "No one";
		checkGrade(*this);
	}

Form::Form(const Form& other) {
	this->_name = other._name;
	this->_isSigned = other._isSigned;
	this->_gradeToSign = other._gradeToSign;
	this->_gradeReguiredToExecute = other._gradeReguiredToExecute;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_isSigned = other._isSigned;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeReguiredToExecute = other._gradeReguiredToExecute;
	}
	return *this;
}

Form::~Form() {}

void Form::setName(std::string value) {_name = value;}

std::string Form::getName() const {return _name;}

void Form::setIsSigned(bool value) {_isSigned = value;}

bool Form::getIsSigned() const {return _isSigned;}

void Form::setGrade(int value) {
	_gradeToSign = value;
	checkGrade(*this);
}

int Form::getGrade() const {return _gradeToSign;}

void Form::setGradeRequided(int value) {
_gradeReguiredToExecute = value;
checkGrade(*this);
}

int Form::getGradeRequided() const {return _gradeReguiredToExecute;}

//----------------------------------------------

void Form::signForm(Bureaucrat& bgrat) {
	if (!_isSigned) {
		if (bgrat.getGrade() < _gradeToSign) {
			setIsSigned(true);
			std::cout << bgrat.getName() << " signs " << _name << std::endl;
		}
		else {
			std::cout << bgrat.getName() << " cannot sign " << _name << " because his grade is too low" << std::endl;
		}
		_isSigned = true;
		_signedBy = bgrat.getName();
	}
	else {
		std::cout << bgrat.getName() << " cannot sign " << _name << " because the form is already signed" << std::endl;
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
	out <<"Form name: " << form.getName() << std::endl << "Form grade: " << form.getGrade() << 
	std::endl << "Form is signed: " << sign << std::endl <<  "Form required grade: " << form.getGradeRequided() << std::endl;
	return out;
}
