#include "B.hpp"

B::B() : Base(){}

B::B() : Base() {}

B::B(const B& other) : Base(other) {}

B& B::operator=(const B& other) {
    if (this != &other) {  // Self-assignment check
    }
    return *this;
}

B::~B() {}

