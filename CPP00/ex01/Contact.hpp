/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:52:22 by timo              #+#    #+#             */
/*   Updated: 2024/08/07 10:55:10 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
	
	public:
		Contact();
		~Contact();
	
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;

		bool setFirstName(std::string name);
		bool setLastName(std::string name);
		bool setNickName(std::string name);
		bool setPhoneNumber(std::string number);
		bool setDarkestSecret(std::string number);
};
