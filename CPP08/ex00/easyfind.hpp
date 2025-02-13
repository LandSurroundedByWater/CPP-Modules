/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:30:30 by tsaari            #+#    #+#             */
/*   Updated: 2025/02/07 11:07:42 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::out_of_range("Value not found in the container");
	}
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
    auto it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::out_of_range("Value not found in the container");
    }
    return it;
}

#endif
