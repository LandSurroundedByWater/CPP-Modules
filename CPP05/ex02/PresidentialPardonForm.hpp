/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:35:53 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/26 07:46:39 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> 


class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void setTarget(std::string target);
    const std::string getTarget() const;

    void execute(Bureaucrat const & executor) const override;

protected:
    std::string _target;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm& form);

#endif // PRESIDENTIALPARDONFORM_HPP
