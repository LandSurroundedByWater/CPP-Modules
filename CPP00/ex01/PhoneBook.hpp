/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:49:50 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/18 17:03:00 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>



class PhoneBook 
{
private:
	Contact	contacts[8];
	int 	_index;

public:
	PhoneBook();
	~PhoneBook();
	void intro(void) const;
	void add_contact(void);
	void searchContact (void) const;
	void printSpecificContact (void) const;
};


#endif