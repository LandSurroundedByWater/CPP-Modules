#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Aform(), {}

ShrubberyCreationForm::ShrubberyCreationForm(int _target) : Aform(), _target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Aform(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {  // Self-assignment check
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::set_target(int value) {
    _target = value;
}

int ShrubberyCreationForm::get_target() const {
    return _target;
}

