#ifndef AForm_HPP
#define AForm_HPP

#include <string>

class AForm {
public:
    AForm();
    AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();


protected:
};

#endif // AForm_HPP
