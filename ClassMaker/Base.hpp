#ifndef Base_HPP
#define Base_HPP

#include <string>

class Base {
public:
    Base();
    Base();
    Base(const Base& other);
    Base& operator=(const Base& other);
    virtual ~Base();


protected:
};

#endif // Base_HPP
