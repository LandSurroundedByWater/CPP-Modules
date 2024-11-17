#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "Aform.hpp"

#include <string>

class ShrubberyCreationForm : public Aform {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(int _target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    void set_target(int value);
    int get_target() const;

protected:
    int _target;
};

#endif // ShrubberyCreationForm_HPP
