/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:09:45 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:09:47 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
#define Brain_HPP

#include <string>
#include <iostream>

class Brain {
	public:
		// Constructors
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void addIdea(std::string idea);
		std::string getIdea(int index);

	private:
		std::string _ideas[100];
		int _index;
};

#endif // Brain_HPP
