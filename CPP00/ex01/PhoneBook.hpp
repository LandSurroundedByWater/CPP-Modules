/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:49:50 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/07 10:54:49 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class PhoneBook 
{
private:
	Contact	contacts[8];
	int 	_index;

public:
	PhoneBook();
	~PhoneBook();
	void intro(void) const;
	void addContact(void);
	void searchContact (void) const;
	void printSpecificContact (void) const;
};

#endif