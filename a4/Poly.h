// Poly.h
#ifndef POLY
#define POLY
#include<iostream>

class Poly{
    // a Poly is a sequence of terms (coefficient, exponent)
    // class invariant: terms are kept in ascending order of
    // exponents
    
public:
    
    Poly();
    // create an polynomial with no terms
    
    ~Poly();
    // return all heap memory
    
    Poly(const Poly & p);
    // copy constructor - construct a deep copy of p
    
    const Poly & operator=(const Poly & p);
    // assignment operator - replace calling Polynomial
    // with a deep copy of p
    
    bool empty()const;
    // return true if polynomial has no terms; else false
    
    int degree()const;
    // return value of highest exponent
    
    void appendTerm(double coeff, int exp);
    // add term coeff^exp at end of polynomial
    // precondition: exp > than exponent of all terms in
    //               the polynomial
    
    void display(std::ostream & out);
    // send polynomial to out
    
    double evaluate(int x);
    // return the result of evaluating polynomial for
    // the value of x provided
    
    Poly operator+(const Poly & p);
    // return the sum of the calling polynomial and p
    
private:
    class Node{
    public:
        double coeff;
        int exp;
        Node * next;
    };
    Node * firstTerm;
    Node * lastTerm;
    int highestExp;  // largest exponent of the polynomial's terms
};
#endif