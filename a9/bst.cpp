//bst.cpp

#include <iostream>
#include "bst.h"
using namespace std;

bool insert2(const ItemType & item, BinNode * & root);
bool search2(BinNode * root, const ItemType & item);
int height2(BinNode * root);
void display2(BinNode * root, ostream & out);
BinNode * getDelete(int item, BinNode * & parent, BinNode * root);
void erase(BinNode * node);
void copy(BinNode * node, BinNode *& node2);

BST::BST() // constructor
{
	root = 0;
	numItems = 0;
}

bool BST::empty() const // method to check if bst is emoty or not
{
	return root == 0;
}

int BST::size() const // method to get size of bst
{
    return numItems;
}

bool BST::insert(const ItemType & item)
{
    bool retVal=insert2(item,root); // calls the helper function
    
    if(retVal) // if item is added, increases the number of items;
        numItems++;
    
	return retVal;
}

bool insert2(const ItemType & item, BinNode * & root)
{
	if( root == NULL ) // if root is empty, adds the item, returns true
	{
		root = new BinNode(item);
		return true;
	}
    
    if( item == root->item ) // if bst has the item, returns false
        return false;
    
	else
	{
		if( item < root->item ) // if item is smaller
			return insert2(item, root->left); // calls insert for the left tree
            
		else if(item > root->item) // if item is bigger
			return insert2(item, root->right); // calls insert for the right tree
	}
    return true; // returns true;
}

bool BST::search(const ItemType & item) const
{
	return search2(root, item); // calls the helper function
}

bool search2(BinNode * root, const ItemType & item)
{
    if (root == NULL) // if root is empty returns false
		return false;
    
    if (root->item == item) // if root has the item, returns true
        return true;
    
	if(item < root->item) // if item is smaller
		return search2(root->left, item); // calls search for the left tree
    
    // if item is bigger
    return search2(root->right, item); // calls search for the right tree
}

int BST::height()const
{
    return height2(this->root); // calls the helper function
}

int height2(BinNode * root)
{
    if ( root == NULL ) // if root is empty returns false
        return 0;
    
    if ( root->right == NULL && root->left == NULL ) // if root doesnt have any child, returns 1
        return 1;
   
    int right=0, left=0;
    
    if(root->right != NULL)
        right=height2(root->right); // gets height of right tree
    
    if(root->left != NULL)
        left=height2(root->left); // gets height of left tree
    
    if(left>right)
        return left+1;
    return right+1;
    // returns the length of bigger sub tree + 1
}

void BST::display(ostream & out)const
{
    display2(root, out); // calls the helper function
    out << endl;
}

void display2(BinNode * root, ostream & out)
{
    if( root != NULL )
    {
        display2(root->left, out); // displays left tree
        out << root->item << " "; // displays root
        display2(root->right, out); // displays right tree
    }
}

bool BST::remove(const ItemType & item)
{
    if ( !search2(root,item) ) // if item is not in the bst, returns false
        return false;
    
    BinNode * parent = NULL; // parent is NULL
    BinNode * currNode = getDelete(item,parent,root); // urrNode is the node with item, parent is its parent
    
    if( currNode->left && currNode->right ) // if it has 2 childs
    {
        BinNode * temp = currNode;
        parent = currNode; // sets parent to current node
        currNode = currNode->left; // sets cuurent node to its left
        
        while( currNode->right != NULL )
        {
            parent = currNode; // sets parent to current node
            currNode = currNode->right; // sets cuurent node to its left
        }
        temp->item = currNode->item; // sets temps item to current nodes item
    }
    
    // if root has 0 or 1 child starts from here
    
    BinNode *temp;
    if( currNode->left!=NULL) // if left is not empty sets temp to left
        temp=currNode->left;
    else
        temp=currNode->right; // else sets temp to right
        
    if(parent==NULL) // if parent is not null, sets root to temp
        root=temp;
    
    else if(parent->item < currNode->item) // else if curr item is bigger than parents item
        parent->right=temp; // parents right is set to temp
    
    else // else (if curr item is smaller than parents item)
        parent->left=temp; // parents left is set to temp
    
    delete currNode; // deletes current node
    numItems--; // decreases numItems
    
    return true;
}

BinNode * getDelete(int item, BinNode * & parent, BinNode * root) // function to get parent and the node with item
{
    BinNode * currNode = root; // currNode is root
    parent=NULL; // parent is null
    
    while(currNode!=NULL && currNode->item!=item) // while currNode is not null an item is not currNode item
    {
        parent = currNode; // parent is currNode
        
        if(item < currNode->item) // if item is smaller then currNode item
            currNode = currNode->left; // currNode is its left
        else // if item is bigger then currNode item
            currNode = currNode->right; // currNode is its right
    }
    
    // if item is currNode item, jumps here
    return currNode; // returns currNode
}

void erase(BinNode * node) // erase function
{
    if(node != NULL)
    {
        erase(node->left); // erases left tree
        erase(node->right); // erases right tree
        delete node; // deletes node
    }
}

BST::~BST()
{
    erase(root); // calls the erase function
}

void copy(BinNode * node, BinNode *& node2) // copy function
{
    if(node != NULL)
    {
        insert2(node->item, node2); // inserts item to node2
        copy(node->left, node2); // copys left tree
        copy(node->right, node2); // copys right tree
    }
}

BST::BST(const BST & original)
{
    root = 0;
	numItems = 0;
    
    copy(original.root, root); // calls the copy function
}

const BST & BST::operator=(const BST & original)
{
    if( this != &original)
    {
        erase(root); // calls the erase function
        
        root = 0;
        numItems = 0;
        
        copy(original.root,root); // calls the copy function
    }
    return *this;
}

