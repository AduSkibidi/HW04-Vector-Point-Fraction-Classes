#ifndef FRACTIONS_H
#define FRACTIONS_H

class Fraction {
public:
    static const char delimiter = '/'; // Default delimiter for fraction representation
private:
    int _numerator = 0;
    int _denominator = 1;
    void _reduce();
public:
    Fraction();
    Fraction(int numerator, int denominator);
    ~Fraction();
public:
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    void setFraction(int numerator, int denominator);
public:
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
public:
    std::string toString() const;
};


#include "Fractions.cpp"
#endif // FRACTIONS_H