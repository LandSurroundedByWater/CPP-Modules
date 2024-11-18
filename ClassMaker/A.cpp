#include "A.hpp"

A::A() : Base(){}

A::A() : Base() {}

A::A(const A& other) : Base(other) {}

A& A::operator=(const A& other) {
    if (this != &other) {  // Self-assignment check
    }
    return *this;
}

A::~A() {}

