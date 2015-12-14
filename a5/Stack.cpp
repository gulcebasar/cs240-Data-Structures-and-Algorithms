 #include <cassert>
#include <iostream>
#include <cstdlib>
#include "Stack.h"

using namespace std;

Stack::Stack(int newCap)
{
	assert( newCap > 0 );
	Capacity=newCap;
	stArray=new StackElement[Capacity];
	Top=-1;
}

Stack::Stack(const Stack& st)
{
    Capacity=st.Capacity;
	stArray=new StackElement[Capacity];
    
    for( int i=0 ; i<sizeof(st.stArray) ; i++ )
    {
        stArray[i]=st.stArray[i];
    }
    
    Top=st.Top;
}

int Stack::size()
{
    return Top+1;
}

bool Stack::empty() const
{
    return (Top == -1);
}

void Stack::push(const StackElement& value)
{
	assert( Top < Capacity -1 );
    
    Top++;
	stArray[Top]=value;
}

void Stack::display(ostream & out) const
{
    for (int i=Top ; i >= 0 ; i--)
        out << stArray[i]<< endl;
}

StackElement Stack::top() const
{
	return (stArray[Top]);
}

Stack Stack::operator=(const Stack& st)
{
    assert( stArray != st.stArray );
    
    delete [] stArray;
    
    Capacity=st.Capacity;
	stArray=new StackElement[Capacity];
    
    for( int i=0 ; i<sizeof(st.stArray) ; i++ )
    {
        stArray[i]=st.stArray[i];
    }
    
    Top=st.Top;
    
    return *this;
}

void Stack::pop()
{
    Top--;
}

Stack::~Stack()
{
    delete [] stArray;
}