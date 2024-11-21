/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:37:12 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/21 09:02:01 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <exception>
#include <iostream>
#include <iostream>   // For std::cerr and std::cout
#include <fstream>    // For std::ofstream
#include "Bureaucrat.hpp"

class AForm {
public:
	AForm();
	AForm(std::string name, bool isSigned, int grade, int executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	void setName(std::string value);
	std::string getName() const;
	void setIsSigned(bool value);
	bool getIsSigned() const;
	void setSignedBy(std::string value);
	std::string getSignedBy() const;
	void setGrade(int value);
	int getGrade() const;
	void setGradeRequided(int value);
	int getGradeRequided() const;


	void signForm(Bureaucrat& bgrat);
	virtual void execute(Bureaucrat const & executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
		public:
			const char *what() const noexcept override;
	};

	class FormAlreadySignedException : public std::exception
	{
		public:
			const char *what() const noexcept override;
	};

	void checkGrade(const AForm& check);

	

private:
	
	std::string _name;
	std::string _signedBy;
	bool _isSigned;
	int _gradeToSign;
	int _gradeReguiredToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // AForm_HPP
