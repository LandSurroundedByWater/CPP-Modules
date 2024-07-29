/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timo <timo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:52:22 by timo              #+#    #+#             */
/*   Updated: 2024/07/18 11:47:04 by timo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
		// funktiot
		std::string get_firstName() const;
		std::string get_lastName() const;
		std::string get_nickName(void) const;
		std::string get_phoneNumber(void) const;
		std::string get_darkestSecret(void) const;

		bool set_firstName(std::string name);
		bool set_lastName(std::string name);
		bool set_nickName(std::string name);
		bool set_phoneNumber(std::string number);
		bool set_darkestSecret(std::string number);
};
