// Priority Queue class
// Each item in a P_Queue has a priority associated with it.
// Items with a higher priority value are removed before those with
//    a lower priority value

#ifndef P_QUEUE
#define P_QUEUE

#include"job.h"

typedef Job ItemType;

class P_Queue{
    
public:
    P_Queue();
    // construct an empty priority queue
    // with a capacity of 10
    
    P_Queue(int capacity);
    // construct an empty priority queue
    // with the specified capacity
    
    P_Queue(const P_Queue& pQue);
    // copy constructor of the priority queue
    
    ~P_Queue();
    // destructor of the priority queue
    
    P_Queue operator=(const P_Queue& pQue);
    // assignment operator of the priority queue
	
    bool empty();
    // is the priority queue empty?
    
    int length();
    // how many items are in the priority queue?
    
    void addItem(const ItemType & item);
    // add an item to the priority queue
    // precondition: P_Queue is not full
	
    ItemType getHighest();
    // return the item with the highest priority value
    // precondition: P_Queue is not empty
	
    void removeHighest();
    //remove the item with the highest priority value
    // precondition: P_Queue is not empty
    
    void display();
    // display contents of the heap
	
private:
	// data members needed to implement a priority queue using a heap
    ItemType * heap;   // for a dynamically allocated array
    int size;		   // number of items in the priority queue
    int capacity;      // maximum number of items allowed
};

#endif



