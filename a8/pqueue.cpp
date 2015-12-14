#include<iostream>
#include<cassert>
#include"pqueue.h"

using namespace std;

P_Queue::P_Queue() // Default constructor, sets capacity to 10
{
	capacity=10;
	size=0;
	heap=new ItemType[capacity];
}

P_Queue::P_Queue(int capacity) // Constructor, sets capacity to given capacity
{
	this->capacity=capacity;
	size=0;
	heap=new ItemType[capacity];
}

P_Queue::P_Queue(const P_Queue& pQue) // Copy constructor
{
    if(pQue.capacity != capacity )
    {
        capacity=pQue.capacity;
        heap=new ItemType[capacity];
    }
    
    size=0;
        
    for( int i=0; i<pQue.size; i++ )
        this->addItem(pQue.heap[i]);
}

P_Queue::~P_Queue() // Destructor
{
    delete []heap;
}

P_Queue P_Queue::operator=(const P_Queue& pQue) // Copy constructor
{
    
    if( capacity != pQue.capacity )
    {
        delete [] heap;
        capacity=pQue.capacity;
        heap=new ItemType[capacity];
    }
    
    size=0;
    for( int i=0; i<pQue.size; i++ )
        this->addItem(pQue.heap[i]);
    
    return *this;
}

bool P_Queue::empty() // returns if it is empty or not
{
	return (size == 0);
}

int P_Queue::length() // returns its lenght
{
	return size;
}

void P_Queue::addItem(const ItemType & item) // adds item to queue
{
    assert ( size != capacity );
	int index=0;
	
	if(size==0) // if its empty
		heap[0] = item; // adds the item
    
    else // if its not empty
    {
        for(int i=0; i<size; i++)
        {
            if(item.getPriority() >= heap[i].getPriority() ) // sorts them by thir priority
                index=i+1;
        }
        
        for(int i=size-1; i>=index; i--) // moves previous items
            heap[i+1]=heap[i];
        
        heap[index]=item; // adds item to the right position
    }
    
    size++; // increases size
}

ItemType P_Queue::getHighest()
{
    assert( size != 0 );
	return heap[0]; // returns the one with highest priority
}

void P_Queue::removeHighest()
{
    assert( size != 0 );
    
	for(int i=0; i<size; i++)
	{
		heap[i]=heap[i+1]; // moves remaining items
	}
	size--; // decreases size
}

void P_Queue::display() // displays queue
{
	for(int i=0; i<size; i++)
	{
		heap[i].display();
	}
	cout <<  endl;
}
