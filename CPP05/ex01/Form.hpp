/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:38:28 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/10 09:50:46 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(std::string name, int grade, int gradeRequired);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		void setIsSigned(bool value);
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeRequidedToExecute() const;
		std::string getSignedBy() const;
		
		void beSigned(Bureaucrat& bgrat);

	private:
		
		const std::string _name;
		std::string _signedBy;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeReguiredToExecute;

		void checkGrade(const Form& check);
		class GradeTooHighException : public std::exception
		{
			public:
				const char  *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char  *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
