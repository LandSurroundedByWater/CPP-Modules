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

//---------- Constructors and destructors---------------------

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {  
        this->_target = other._target;
        this->setIsSigned(other.getIsSigned());
        this->setSignedBy(other.getSignedBy());
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

//------------------------Getters and Setters----------------------

const std::string PresidentialPardonForm::getTarget() const {return _target;}

// Methods

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned()){
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeRequidedToExecute()) {
        throw AForm::GradeTooLowException();
	}
	std::cout << this->getTarget() <<" has been pardoned by Zafod Beeblebrox" << std::endl;	
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm& form) {
    // Call the base class operator<<
    out << static_cast<const AForm&>(form);
    // Append the derived class-specific attribute
    out << "Target: " << form.getTarget() << std::endl;
    return out;
}
