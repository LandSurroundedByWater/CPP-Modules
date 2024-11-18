#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

#include <string>

class A : public Base {
public:
    A();
    A();
    A(const A& other);
    A& operator=(const A& other);
    virtual ~A();


protected:
};

#endif // A_HPP
