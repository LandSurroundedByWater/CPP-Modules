#include "Form.hpp"

Form::Form() : _name("DefaultForm"),
    _isSigned(false),
    _grade(150),
    _gradeReguired(1) {}

Form::Form(std::string name, bool isSigned, int grade, int gradeRequired) :
    _name(name),
    _isSigned(isSigned),
    _grade(grade),
    _gradeReguired(gradeRequired) {}

Form::Form(const Form& other) {
    this->_name = other._name;
    this->_isSigned = other._isSigned;
    this->_grade = other._grade;
    this->_gradeReguired = other._gradeReguired;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_isSigned = other._isSigned;
        this->_grade = other._grade;
        this->_gradeReguired = other._gradeReguired;
    }
    return *this;
}

Form::~Form() {}

void Form::setName(std::string value) {
    _name = value;
}

std::string Form::getName() const {
    return _name;
}

void Form::setIsSigned(bool value) {
    _isSigned = value;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

void Form::setGrade(int value) {
    _grade = value;
}

int Form::getGrade() const {
    return _grade;
}

void Form::setGradeRequided(int value) {
    _gradeReguired = value;
}

int Form::getGradeRequided() const {
    return _gradeReguired;
}

std::ostream &operator<<(std::ostream &out, const Form& form)
{
    std::string sign = "false";
    if (form.getIsSigned())
    {
        sign = "true";
    }
	out <<"Form name: " << form.getName() << std::endl << "Form grade: " << form.getGrade() << 
    std::endl << "Form is signed: " << sign << std::endl <<  "Form required grade: " << form.getGradeRequided() << std::endl;
	return out;
}
