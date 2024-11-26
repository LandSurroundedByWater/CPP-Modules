/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:35:53 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/26 07:19:37 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> 


class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void setTarget(std::string target);
    const std::string getTarget() const;

    void execute(Bureaucrat const & executor) const override;


protected:
    std::string _target;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm& form);

#endif // RobotomyRequestForm_HPP
