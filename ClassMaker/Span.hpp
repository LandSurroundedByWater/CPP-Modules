#ifndef Span_HPP
#define Span_HPP

#include <string>

class Span {
public:
    // Constructors
    Span();
    Span(int _n, UnknownType _v);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void set_n(int value);
    int get_n() const;
    void set_v(UnknownType value);
    UnknownType get_v() const;

private:
    int _n;
    UnknownType _v;
};

#endif // Span_HPP
