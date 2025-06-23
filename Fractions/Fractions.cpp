#include "Fractions.h"
#include "../utils/utils.h"
#include <iostream>

void Fraction::_reduce() {
    int gcdValue = gcd(_numerator, _denominator);
    _numerator /= gcdValue;
    _denominator /= gcdValue;
}

Fraction::Fraction() {
    _numerator = 0;
    _denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        std::cerr << "Lỗi: Mẫu số không thể là 0!\n";
        exit(1);
    }
    _numerator = numerator;
    _denominator = denominator;
    _reduce();
}

const char Fraction::delimiter;

Fraction::~Fraction() {
    // Destructor does not need to do anything special
}

int Fraction::getNumerator() const {
    return _numerator;
}

int Fraction::getDenominator() const {
    return _denominator;
}

void Fraction::setNumerator(int numerator) {
    _numerator = numerator;
}

void Fraction::setDenominator(int denominator) {
    if (denominator == 0) {
        std::cerr << "Lỗi: Mẫu số không thể là 0!\n";
        exit(1);
    }
    _denominator = denominator;
}

void Fraction::setFraction(int numerator, int denominator) {
    if (denominator == 0) {
        std::cerr << "Lỗi: Mẫu số không thể là 0!\n";
        exit(1);
    }
    _numerator = numerator;
    _denominator = denominator;
    _reduce();
}

Fraction Fraction::operator+(const Fraction& other) const {
    int newNumerator = _numerator * other._denominator + other._numerator * _denominator;
    int newDenominator = _denominator * other._denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int newNumerator = _numerator * other._denominator - other._numerator * _denominator;
    int newDenominator = _denominator * other._denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int newNumerator = _numerator * other._numerator;
    int newDenominator = _denominator * other._denominator;
    return Fraction(newNumerator, newDenominator);
}

std::string Fraction::toString() const {
    if (_denominator == 1) {
        return std::to_string(_numerator);
    }
    
    return std::to_string(_numerator) + delimiter + std::to_string(_denominator);
}
