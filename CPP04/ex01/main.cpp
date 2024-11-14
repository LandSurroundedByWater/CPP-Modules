/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:10:19 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:10:21 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"



int main() 
{
	int amount = 10;

	std::cout << "--------------Creating cats and dogs -------------------------" << std::endl;

	Animal* catsAndDogs[amount];
	for (int i = 0; i < amount; ++i)
	{
		std::cout << i << std::endl;
		if (i % 2 == 0)
			catsAndDogs[i] = new Dog;
		else
			catsAndDogs[i] = new Cat;
	}
	std::cout << std::endl;
	std::cout << "-------------Checking how brains are working-------------------------" << std::endl << std::endl;
	catsAndDogs[1]->getBrain()->addIdea("Food!!!!!!");
	catsAndDogs[1]->getBrain()->addIdea("That's a strange idea I'm having");
	catsAndDogs[1]->getBrain()->addIdea("Ball!!!!!");
	catsAndDogs[1]->getBrain()->addIdea("Squirrel!!!!!");

	std::cout << "First idea of catsAndDogs[1]: " << catsAndDogs[1]->getBrain()->getIdea(0) << std::endl;

	std::cout << "Assigning catsAndDogs[1] to catsAndDogs[3]" << std::endl;
	Cat* cat3 = dynamic_cast<Cat*>(catsAndDogs[3]);
	Cat* cat1 = dynamic_cast<Cat*>(catsAndDogs[1]);

	if (cat1 && cat3)  // Ensure both casts are successful
	{
		*cat3 = *cat1;  // Use the assignment operator to copy cat1 to cat2
		std::cout << "First idea of catsAndDogs[3]: " << cat3->getBrain()->getIdea(0) << std::endl;
	}
	else
	{
		std::cout << "Please, do not try to combine cats and dogs." << std::endl;
	}
	std::cout << std::endl;
	std::cout << "--------------Deleting cats and dogs -------------------------" << std::endl << std::endl;

		for (int i = 0; i < amount; ++i)
		{
			std::cout << i << std::endl;
			delete catsAndDogs[i];
		}

	return 0;
}

