#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

#include <string>

class B : public Base {
public:
    B();
    B();
    B(const B& other);
    B& operator=(const B& other);
    virtual ~B();


protected:
};

#endif // B_HPP
