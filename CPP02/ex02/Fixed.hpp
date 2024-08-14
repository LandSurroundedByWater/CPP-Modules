/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:57:57 by tsaari            #+#    #+#             */
/*   Updated: 2024/07/23 10:13:15 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
#include <cmath> 

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;
	
	public:
	
	Fixed();
	~Fixed();
	Fixed( const int n );
	Fixed( const float n );

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif