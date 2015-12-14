#include <iostream>

#ifndef STACK
#define STACK

typedef double StackElement;

using namespace std;

class Stack
{
    
public:
    
    Stack(int numElements=50);
    Stack(const Stack& st);
    bool empty() const;
    void push(const StackElement &value);
    void display(ostream & out) const;
    void pop();
    int size();
    StackElement top() const;
    Stack operator=(const Stack& st);
    ~Stack();
    
private:
    int Capacity;
    StackElement *stArray;
    int Top;
};

#endif