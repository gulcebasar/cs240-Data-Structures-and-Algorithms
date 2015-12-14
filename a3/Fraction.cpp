#include "Fraction.h"
#include <iostream>
#include <cassert>
#include <cmath>

Fraction::Fraction()
{
    num=0;
    den=1;
}

Fraction::Fraction(int a, int b)
{
    assert( b != 0 );

    
    for(int i=b; i>=2; i--)
    {
        if(a%i==0 && b%i==0)
        {
            a=a/i;
            b=b/i;
        }
    }
    num=a;
    den=b;
}

int Fraction::getNumarator() const{
    return num;
}

int Fraction::getDenominator() const{
    return den;
}

Fraction Fraction::operator+(const Fraction& f) const
{
    return Fraction((num*f.den)+(f.num*den), den*f.den);
}

Fraction Fraction::operator-(const Fraction& f) const
{
    Fraction temp=f;
    temp.negate();
    int x=(num*temp.den)+(temp.num*den);
    int y=den*temp.den;
    return Fraction(x, y);
}

Fraction Fraction::operator*(const Fraction& f) const
{
    return Fraction(num*f.num, den*f.den);
}

Fraction Fraction::operator/(const Fraction& f) const
{
    Fraction temp=f;
    temp.invert();
    return Fraction(num*temp.num, den*temp.den);
}

double operator/(const int& i) const
{
    double temp = num/den;
    return temp/i;
}

bool Fraction::operator<(const Fraction& f) const
{
    double f1=(double)num / (double)den;
    double f2=(double)f.num / (double)f.den;
    return (f1<f2);
}

bool Fraction::operator>(const Fraction& f) const
{
    double f1=(double)num / (double)den;
    double f2=(double)f.num / (double)f.den;
    return (f1>f2);
}

bool Fraction::operator<=(const Fraction& f) const
{
    double f1=(double)num / (double)den;
    double f2=(double)f.num / (double)f.den;
    return (f1<=f2);
}

bool Fraction::operator>=(const Fraction& f) const
{
    double f1=(double)num / (double)den;
    double f2=(double)f.num / (double)f.den;
    return (f1>=f2);
}

bool Fraction::operator==(const Fraction& f) const
{
    double f1=(double)num / (double)den;
    double f2=(double)f.num / (double)f.den;
    return (f1==f2);
}

bool Fraction::operator!=(const Fraction& f) const
{
    double f1=(double)num / (double)den;
    double f2=(double)f.num / (double)f.den;
    return (f1!=f2);
}

ostream& operator<<(ostream& out, const Fraction& f)
{
    
    if(f.num>f.den)
    {
        int i=0;
        int n=f.num;
        do
        {
            n=n-f.den;
            i++;
        }while(n>=f.den);
        
        out << i << "+" << n << "/" << f.den ;
    }
    else
    {
        out <<  f.num << "/" << f.den ;
    }
    return out;
}

void Fraction::invert(){
    assert( num != 0 );
    int temp;
    
    if(num<0)
    {
        temp=-num;
        num=-den;
        den=temp;
    }
    else
    {
        temp=num;
        num=den;
        den=temp;
    }
}

void Fraction::negate(){
    num=-num;
}
