/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:57:57 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/13 11:18:55 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
#include <cmath> 

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;
	
	public:
	
	Fixed();
	~Fixed();
	Fixed(const int n);
	Fixed(const float n);

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif