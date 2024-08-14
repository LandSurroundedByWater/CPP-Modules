/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:18:54 by tsaari            #+#    #+#             */
/*   Updated: 2024/08/14 09:02:49 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{	
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void unknown(void);
		
		typedef void (Harl::*t_function)();

		enum Level {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		UNKNOWN
		};
		
		Level getLevel(const std::string& level) const;
		
	public:
		Harl();
		~Harl();
		void complain( std::string level );

};

#endif