// SimpleList.h

#ifndef SIMPLELIST
#define SIMPLELIST

#include<string>
#include"Fraction.h"
using namespace std;

const int CAPACITY = 10;  // max number of items
typedef Fraction ItemType;  // type of item to be stored

class SimpleList{
// a container that holds a sequence of items that can be 
//    accessed by position
// class invariant:  items are stored in positions 0 to n-1 where
//    n is the the number of items stored and n <= CAPACITY

	friend ostream& operator<<(ostream&, SimpleList& sl);
    
    public:
        SimpleList();
        // create a SimpleList with 0 items in it
    
        SimpleList( SimpleList& sl );
        // creates a simple list identical to the inserted SimpleList
    
        SimpleList & operator=( SimpleList& sl );
        // overloads the = operator

        ~SimpleList();
        // destructor of SimpleList

        bool empty () const;
        // return true if SimpleList holds 0 items
    
        void makeEmpty();
        // makes the list empty
        
        int listSize ()const;
        // return number of items in SimpleList

        void append (const ItemType & item);
        // insert item at the end of SimpleList
        // precondition: SimpleList has not reached its capacity
        
        ItemType & retrieve (int position);
        // return a reference to the item stored at specified  
        //    position in SimpleList
        // precondition: position >=0 and < number of items -1
    
        void insert (int index, const ItemType & item);
        // adds ItemType to index
        // precondition: size < CAPACITY and index < size
    
        void remove (int index);
        // removes index'th ItemType
        // precondition: size > 0 and index < size

        ItemType & operator[](int position) ;
        // return a reference to the item stored at specified  
        //    position in SimpleList
        // precondition: position >=0 and < number of items -1
                     
 	private:
 		 ItemType* list; 
 		 int size;
}; 
#endif   
        
