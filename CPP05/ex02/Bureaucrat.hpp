/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:36:30 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/26 08:15:14 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();


	void setName(std::string value);
	std::string getName() const;
	void setGrade(int value);
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();

	bool signForm(int gradeToSign, std::string formName);

private:
	std::string _name;
	int _grade;

	void checkGrade(const Bureaucrat& check);
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bgrat);

#endif // Bureaucrat_HPP
