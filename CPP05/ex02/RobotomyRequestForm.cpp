/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:35:42 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/17 18:42:14 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors and destructors

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {  
        this->_target = other._target;
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
	if (executor.getGrade() > this->getGradeRequided()){
		std::cout << "Robotomy failed!" << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (!this->getIsSigned()){
		std::cout << "Robotomy failed!" << std::endl;
		throw AForm::FormNotSignedException();
	}
	std::cout << "Drilling noise..." << std::endl;
	std::cout << this->getTarget() <<" has been robotomized successfully 50'%' of the time" << std::endl;
	std::cout << "Form signed by: " << this->getSignedBy() << std::endl;
	std::cout << "Executor: " << executor.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm& form) {
    // Call the base class operator<<
    out << static_cast<const AForm&>(form);
    // Append the derived class-specific attribute
    out << "Target: " << form.getTarget() << std::endl;
    return out;
}
