#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

#include <string>

class C : public Base {
public:
    C();
    C();
    C(const C& other);
    C& operator=(const C& other);
    virtual ~C();


protected:
};

#endif // C_HPP
