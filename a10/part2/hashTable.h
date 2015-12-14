#ifndef HASHTABLE
#define HASHTABLE
#include<cstring>
#include<iostream>
#include<cstdlib>

using namespace std;
typedef string itemType;

class Node // class node
{
public:
    itemType item;
    Node* next;
    Node* firstTerm;
    Node* lastTerm;

    Node() // default constructor of node
    {
        next=NULL; // sets next to NULL
        firstTerm=NULL; // sets firstTerm to NULL
        lastTerm=NULL; // sets lastTerm to NULL
    }
};

class HashTable{
public:
    
    HashTable(int (*func)(itemType), int newSize);
    // sets *hFunc to func, size to newSize
    
    bool insert(const itemType & item);
    // returns true if item is inserted, false otherwise
    
    bool find(const itemType & item) const;
    // returns true if item is found, false otherwise
    
    double loadFactor() const;
    // returns the load factor of hashTable
    
    double avgLenght() const;
    //returns the average lenght of hashTable
    
    ~HashTable();
    //destructor of hashTable
    
private:
    int (* hFunc) (itemType key); // a function pointer to hold the hashFunction
    int size; // size of the hash table
    Node* hashTab; // an array to hold linkedlists
};
#endif


