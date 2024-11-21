
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>


Base* generate()
{
	int random = rand() % 3;
	switch (random)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer: C" << std::endl;
	else if (p == NULL)
		std::cout << "pointer: NULL" << std::endl;
	else
		std::cout << "Type: Unknown" << std::endl;
}

void identify(Base& p)
{
	bool isCorrect = false;

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "reference A" << std::endl;
		isCorrect = true;
	}
	catch (std::exception &e){};
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "reference B" << std::endl;
		isCorrect = true;
	}
	catch (std::exception &e){};
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "reference C" << std::endl;
		isCorrect = true;
	}
	catch (std::exception &e){};
	if (!isCorrect)
	{
		std::cout << "Type: Unknown" << std::endl;
	}

}