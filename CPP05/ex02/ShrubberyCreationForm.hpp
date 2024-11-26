/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:36:10 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/26 07:20:07 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> 


class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void setTarget(std::string target);
    const std::string getTarget() const;

    void execute(Bureaucrat const & executor) const override;


protected:
    std::string _target;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form);

#endif // ShrubberyCreationForm_HPP
