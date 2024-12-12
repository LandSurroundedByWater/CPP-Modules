/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:35:42 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/10 09:58:41 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors and destructors

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {  
		this->_target = other._target;
		this->setIsSigned(other.getIsSigned());
		this->setSignedBy(other.getSignedBy());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Getters and Setters

void RobotomyRequestForm::setTarget(std::string target) {_target = target;}

const std::string RobotomyRequestForm::getTarget() const {return _target;}

// Methods


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::srand(std::time(0));
	if (!this->getIsSigned()){
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeRequidedToExecute()) {
		
		throw AForm::GradeTooLowException();
	}
	std::cout << "Drilling noise..." << std::endl;

	int random = rand() % 2;
	if(random == 1)
		std::cout << this->getTarget() <<" has been robotomized successfully!" << std::endl;
	else 
		std::cout << "Robotomy failed!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm& form) {
	// Call the base class operator<<
	out << static_cast<const AForm&>(form);
	// Append the derived class-specific attribute
	out << "Target: " << form.getTarget() << std::endl;
	return out;
}
