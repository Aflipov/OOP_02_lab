#pragma once
#include <initializer_list>
#include <iostream>
#include "array.h"

class Four {
public:
    Four();
    Four(const std::string& str);
    Four(std::initializer_list<unsigned char>);
    Four(const Four&);
    Four(Four&&) noexcept;
    ~Four() noexcept;

    unsigned char get(size_t) const;
    int len() const;
    std::string to_string() const;

    void print(std::ostream& out = std::cout) const;

    static Four add4(const Four&, const Four&);
    static Four sub4(const Four&, const Four&);

    static bool equals(const Four&, const Four&);
    static bool greater(const Four&, const Four&);
    static bool less(const Four&, const Four&);
    static bool notequals(const Four&, const Four&);
    static bool equalsgreater(const Four&, const Four&);
    static bool equalsless(const Four&, const Four&);

    Array digits;

private:
    void delZeroes();
};
