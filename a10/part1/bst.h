// define a binary search tree type  -  BST
// a BST stores a collection of items of type ItemType
// duplicate items are not allowed
// objects of type ItemType must be comparable using the
// relational operators:  == and <

#ifndef _BST_
#define _BST_
#include<cstring>
#include<iostream>
using namespace std;

typedef string ItemType;

// a binary search tree contains nodes of type BinNode
// data members are public because BinNode type is
// intended for use by the BST class only
class BinNode{
public:
    ItemType item;
    BinNode * left;
    BinNode * right;
    BinNode(){
        left = 0;
        right = 0;
    }
    BinNode(const ItemType & newItem){
        left = 0;
        right = 0;
        item = newItem;
    }
};

class BST{
public:
    
    BST();
    // create an empty BST
    
    bool empty()const;
    // is the BST empty?
    
    int size()const;
    // how many items are in the BST?
    
    bool insert(const ItemType & item);
    // add item (if it is not a duplicate) to the BST
    // return true if the item was inserted, otherwise false
    
    bool search(const ItemType & item) const;
    // return true if item is found in the BST, otherwise false
    
    int height()const;
    // return the height (length of the longest path)of the BST
    
    void display(ostream & out)const;
    // display the items in the BST from smallest to largest
    
    bool remove(const ItemType & item);
    // remove item from the BST
    // return true if item was found and removed, otherwise false
    
    ~BST();
    // destructor
    
    BST(const BST & original);
    // copy constructor
    
    const BST & operator=(const BST & original);
    // overloaded assignment operator
    
private:
    BinNode * root;   // gives access to the BST
    int numItems;     // number of items in the BST
};
#endif


