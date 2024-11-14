#ifndef Form_HPP
#define Form_HPP

#include <string>
#include <exception>
#include <iostream>

class Form {
public:
    Form();
    Form(std::string name, bool isSigned, int grade, int gradeRequired);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    void setName(std::string value);
    std::string getName() const;
    void setIsSigned(bool value);
    bool getIsSigned() const;
    void setGrade(int value);
    int getGrade() const;
    void setGradeRequided(int value);
    int getGradeRequided() const;

private:
    std::string _name;
    bool _isSigned;
    int _grade;
    int _gradeReguired;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif // Form_HPP
