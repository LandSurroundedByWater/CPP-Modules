#include "Span.hpp"

Span::Span() {}

Span::Span(int _n, UnknownType _v) :
    _n(_n),
    _v(_v) {}

Span::Span(const Span& other) {
    this->_n = other._n;
    this->_v = other._v;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {  // Self-assignment check
        this->_n = other._n;
        this->_v = other._v;
    }
    return *this;
}

Span::~Span() {}

void Span::set_n(int value) {
    _n = value;
}

int Span::get_n() const {
    return _n;
}

void Span::set_v(UnknownType value) {
    _v = value;
}

UnknownType Span::get_v() const {
    return _v;
}

