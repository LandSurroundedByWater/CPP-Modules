
#ifndef AMATERIA_HPP
#define AMATERI_HPP

#include <string>
#include <iostream>

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const & type);
		~AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif