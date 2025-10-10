#include "../include/four.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>

Four::Four(const std::string& str) : digits(str) {
    delZeroes();
}

Four::Four() : digits() {
    digits.push(0);
}

Four::Four(std::initializer_list<unsigned char> lst) : digits() {
    if (lst.size() == 0)
        digits.push(0);
    else {
        for (auto d : lst)
            digits.push(d);
    }
    delZeroes();
}

Four::Four(const Four& other) : digits(other.digits) {}

Four::Four(Four&& other) noexcept : digits(std::move(other.digits)) {}

Four::~Four() noexcept = default;

unsigned char Four::get(size_t idx) const {
    return digits.get(idx);
}

int Four::len() const {
    return digits.len();
}

std::string Four::to_string() const {
    std::string result;
    for (int i = digits.len() - 1; i >= 0; --i) {
        unsigned char d = digits.get(i);
        result += char('0' + d);
        if (i > 0) result += " ";
    }
    return result;
}

void Four::print(std::ostream& out) const {
    out << to_string();
}

// --- сравнения ---

bool Four::equals(const Four& a, const Four& b) {
    if (a.len() != b.len()) return false;
    for (int i = 0; i < a.len(); ++i)
        if (a.get(i) != b.get(i)) return false;
    return true;
}

bool Four::greater(const Four& a, const Four& b) {
    if (a.len() != b.len()) return a.len() > b.len();
    for (int i = a.len() - 1; i >= 0; --i) {
        if (a.get(i) != b.get(i)) return a.get(i) > b.get(i);
    }
    return false;
}

bool Four::less(const Four& a, const Four& b) {
    if (a.len() != b.len()) return a.len() < b.len();
    for (int i = a.len() - 1; i >= 0; --i) {
        if (a.get(i) != b.get(i)) return a.get(i) < b.get(i);
    }
    return false;
}

bool Four::notequals(const Four& a, const Four& b) {
    return !equals(a, b);
}

bool Four::equalsgreater(const Four& a, const Four& b) {
    return greater(a, b) || equals(a, b);
}

bool Four::equalsless(const Four& a, const Four& b) {
    return less(a, b) || equals(a, b);
}

// --- сложение ---

Four Four::add4(const Four& a, const Four& b) {
    Four res;
    res.digits.clear();

    size_t n = std::max(a.len(), b.len());
    unsigned char carry = 0;

    for (size_t i = 0; i < n; ++i) {
        unsigned char da = (i < a.len()) ? a.get(i) : 0;
        unsigned char db = (i < b.len()) ? b.get(i) : 0;
        unsigned char s = da + db + carry;
        carry = s / 4;
        res.digits.push(s % 4);
    }
    if (carry) res.digits.push(carry);
    res.delZeroes();
    return res;
}

// --- вычитание ---

Four Four::sub4(const Four& a, const Four& b) {
    if (less(a, b)) throw std::invalid_argument("error: negative result");

    Four res;
    res.digits.clear();

    unsigned char borrow = 0;
    for (size_t i = 0; i < a.len(); ++i) {
        int da = a.get(i) - borrow;
        int db = (i < b.len()) ? b.get(i) : 0;
        if (da < db) {
            da += 4;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.digits.push(static_cast<unsigned char>(da - db));
    }
    res.delZeroes();
    return res;
}

void Four::delZeroes() {
    while (digits.len() > 1 && digits.get(digits.len() - 1) == 0)
        digits.pop();
}
