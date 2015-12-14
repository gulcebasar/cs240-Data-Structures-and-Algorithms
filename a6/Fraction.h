#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction{
    friend ostream& operator<< (ostream&, const Fraction&);
private:
    int den, num;
public:
    Fraction();
    Fraction( int, int);
    int getNumarator() const;
    int getDenominator() const;
    Fraction operator+(const Fraction&) const;
    Fraction operator-(const Fraction&) const;
    Fraction operator*(const Fraction&) const;
    Fraction operator/(const Fraction&) const;
    Fraction operator+(const int&);
    double operator/(const double&);
    bool operator<(const Fraction&) const;
    bool operator>(const Fraction&) const;
    bool operator<=(const Fraction&) const;
    bool operator>=(const Fraction&) const;
    bool operator==(const Fraction&) const;
    bool operator!=(const Fraction&) const;
    void negate();
    void invert();
};

#endif