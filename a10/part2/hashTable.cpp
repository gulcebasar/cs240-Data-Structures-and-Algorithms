#include<cstring>
#include<iostream>
#include"hashTable.h"

using namespace std;
void addNode(itemType item, Node * host);

HashTable::HashTable(int (*func)(itemType), int newSize)
{
    size=newSize; // sets size to newSize
    hashTab = new Node[size]; // gets memory for hashTab
    hFunc = func; // sets *hFunc to func
}

bool HashTable::insert(const itemType & item)
{
    bool check = find(item); // true if item allready exists, false otherwise
    if (!check)
        addNode(item, &hashTab[hFunc(item)]); // adds item if item doesnt exist

   return check; // returns true if inserted
}

void addNode(itemType item, Node * host) // helper function
{
    Node* temp = new Node; // creates a new node
    temp->item = item; // sets its item to item
    
    if( host->firstTerm == NULL ) // if host doesnt have any term
    {
        host->firstTerm = temp; //sets first to temp
        host->lastTerm = temp; // sets last to temp
        host->lastTerm->next=NULL; // makes its nest empty
    }
    else // if there items in it
    {
        host->lastTerm->next=temp; // sets lasts next to temp
        host->lastTerm=temp; // sets last to temp
    }
}

bool HashTable::find(const itemType & item) const
{
    Node* temp = hashTab[hFunc(item)].firstTerm;
    // sets temp to the firsttetm of the index with items hashFunction result
    
    while(temp != NULL) // if temp is not null
    {
        if(temp->item == item) // if item is found returns true
            return true;
        temp=temp->next; // else checks the next item
	}
    return false; // returns false if item is not found
}

double HashTable::loadFactor() const
{
    int nonEmptyNode=0;
    
    for (int i=0; i<size; i++)
        if(hashTab[i].firstTerm != NULL) // if the index is not null
            nonEmptyNode++; // increases the number of non empty nodes
    
    return ((double)nonEmptyNode)/((double)size);
}

double HashTable::avgLenght() const
{
    int nonEmptyNode=0;
    int totNodeLength=0;
    Node * temp;
    
    for (int i=0; i<size; i++)
        if(hashTab[i].firstTerm != NULL) // if the index is not null
        {
            nonEmptyNode++; // increases the number of non empty nodes
            temp=hashTab[i].firstTerm; // sets temp to firtsterm
            do{
                totNodeLength++; // increases tot node lenght
                temp=temp->next; // gets the next node
            }while(temp != NULL); // until its null
        }
    
    return ((double)totNodeLength)/((double)nonEmptyNode);
}

HashTable::~HashTable() // destructor of hash table
{
    Node *temp;
    
    for(int i=0; i<size; i++)
    {
        temp=hashTab[i].firstTerm;
        while(temp != NULL)
        {
            delete temp;
            temp=temp->next;
        }
    }
}


