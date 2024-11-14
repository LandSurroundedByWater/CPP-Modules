/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:08:51 by tsaari            #+#    #+#             */
/*   Updated: 2024/09/20 09:08:53 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	}
	std::cout << std::endl;
	{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	}
	return 0;
}


/*int main() {

	std::cout << std::endl;
	Cat myCat;
	std::cout << "Type: " << myCat.getType() << std::endl;
	myCat.makeSound();
	std::cout << std::endl;
	Cat anotherCat(myCat);
	std::cout << "Type of anotherCat: " << anotherCat.getType() << std::endl;
	anotherCat.makeSound();
	std::cout << std::endl;
	Cat assignedCat;
	assignedCat = myCat;
	std::cout << "Type of assignedCat: " << assignedCat.getType() << std::endl;
	assignedCat.makeSound();
	std::cout << std::endl;
	Dog myDog;
	myDog.makeSound();
	std::cout << std::endl;
	return 0;
}*/

