/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:38:28 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/26 08:14:08 by tsaari           ###   ########.fr       */
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
	Form(std::string name, bool isSigned, int grade, int gradeRequired);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	void setName(std::string value);
	std::string getName() const;
	void setIsSigned(bool value);
	bool getIsSigned() const;
	void setGrade(int value);
	int getGrade() const;
	void setGradeRequided(int value);
	int getGradeRequided() const;
	void beSigned(Bureaucrat& bgrat);

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

private:
	
	std::string _name;
	std::string _signedBy;
	bool _isSigned;
	int _gradeToSign;
	int _gradeReguiredToExecute;

	void checkGrade(const Form& check);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif // Form_HPP
