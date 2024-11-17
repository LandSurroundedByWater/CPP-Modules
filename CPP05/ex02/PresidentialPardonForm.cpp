/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:35:42 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/17 11:25:01 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors and destructors

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {  
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Getters and Setters

void PresidentialPardonForm::setTarget(std::string target) {_target = target;}

const std::string PresidentialPardonForm::getTarget() const {return _target;}

// Methods

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeRequided()){
		throw AForm::GradeTooLowException();
	}
	if (!this->getIsSigned()){
		throw AForm::FormNotSignedException();
	}

	std::cout << this->getTarget() <<" has been pardoned by Zafod Beeblebrox" << std::endl;	
	std::cout << "Form signed by: " << this->getSignedBy() << std::endl;
	std::cout << "Executor: " << executor.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm& form) {
    // Call the base class operator<<
    out << static_cast<const AForm&>(form);
    // Append the derived class-specific attribute
    out << "Target: " << form.getTarget() << std::endl;
    return out;
}
