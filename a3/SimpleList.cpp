#include <cassert>
#include <iostream>
#include "SimpleList.h"
#include"Fraction.h"

using namespace std;
 
 SimpleList::SimpleList(): size(0){ // Constructor sets size to 0
	list=new ItemType[CAPACITY]; // allocates memory as the size of CAPACITY
 }

 SimpleList::SimpleList( SimpleList& sl ){
     list=new ItemType[CAPACITY]; // allocates memory as the size of CAPACITY
     this->makeEmpty(); // Makes the list empty (list size=0)
     
     for(int i=0; i<sl.listSize(); i++) // Starts a loop from 0 to sl's size
     {
         this->append(sl[i]); // adds sl[i] to the list
     }
     cout << "COPY CONSTRUCTOR\n";
 }

 SimpleList& SimpleList::operator=( SimpleList& sl ){
     this->makeEmpty(); // Makes the list empty (list size=0)
     
     for(int i=0; i<sl.listSize(); i++) // Starts a loop from 0 to sl's size
     {
         this->append(sl[i]); // adds sl[i] to the list
     }
     cout << "'=' OPERATOR\n";
     
     return *this; // returns the SimpleList
 }

 bool SimpleList::empty () const{
 	return size == 0; // returns true if size is 0
 }

 void SimpleList::makeEmpty (){
    size = 0; // sets size to 0
 }
 
 int SimpleList::listSize () const{
 	return size; // returns size
 }
 
 void SimpleList::append (const ItemType & item){
 	assert(size < CAPACITY); // checks if size is smaller than CAPACITY
 	list[size] = item; // sets list[size] to item
 	size++; // increases size
 }

 void SimpleList::insert (int index, const ItemType & item){
 	assert(size < CAPACITY && index < size); // checks if size is smaller than CAPACITY and index is smaller than size
    
    for(int i=size; i>index; i--) // starts a loop from size to index
    {
        list[i]=list[i-1]; // sets list[i] to list[i-1]
    }
    
 	list[index] = item; // sets list[index] to item
 	size++; // increases size
 }

 void SimpleList::remove (int index){
 	assert(size > 0 && index<size); // checks if index is pozitive and smaller than size
     
     for(int i=index; i<size; i++) // starts a loop from index to size
    {
        list[i]=list[i+1]; // sets list[i] to list[i+1];
    }
 	size--; // decreases size
 }
 
 ItemType & SimpleList::retrieve (int position){
 	assert (position >= 0 && position < size); // checks if position is pozitive and smaller than size
 	return list[position]; // returns position index'th ItemType
 }

 ItemType& SimpleList::operator[](int position) {
 	assert (position >= 0 && position < size); // checks if position is pozitive and smaller than size
     return list[position]; // returns position index'th ItemType
 }

 ostream& operator<<(ostream &out, SimpleList& sl){
	assert ( sl.listSize()<CAPACITY ); // checks if sl's size is smaller than CAPACITY
     
    if(sl.empty()) out << " Empty List "; // If the list is empty prints empty list
     
    else // If the list is not empty
    {
        for( int i=0 ; i<sl.listSize() ; i++ ) // Starts a loop from 0 to sl's size
        {
            out << sl[i] << " "; // Adds i'th ItemType to out
        }
    }
	out << endl;
        
	return out; // returns out
 }

 SimpleList::~SimpleList(){
	delete [] list; // Deletes the accocated memory in constructor
	cout << "DESTRUCTOR\n";
 }

