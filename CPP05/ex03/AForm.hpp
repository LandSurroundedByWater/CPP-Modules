/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:37:12 by tsaari            #+#    #+#             */
/*   Updated: 2024/12/10 09:53:13 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	public:
		AForm();
		AForm(std::string name, int grade, int executeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		void setIsSigned(bool value);
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeRequidedToExecute() const;
		std::string getSignedBy() const;
		void setSignedBy(std::string signedBy);
		void beSigned(Bureaucrat& bgrat);
		
		virtual void execute(Bureaucrat const & executor) const = 0;

	protected:

		void checkGrade(const AForm& check);

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

	private:
		
		const std::string _name;
		std::string _signedBy;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeReguiredToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // AForm_HPP
