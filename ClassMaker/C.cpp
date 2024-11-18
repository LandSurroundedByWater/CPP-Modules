#include "C.hpp"

C::C() : Base(){}

C::C() : Base() {}

C::C(const C& other) : Base(other) {}

C& C::operator=(const C& other) {
    if (this != &other) {  // Self-assignment check
    }
    return *this;
}

C::~C() {}

