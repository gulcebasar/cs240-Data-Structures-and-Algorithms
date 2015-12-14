#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    
	BST m1;
    m1.insert(10);
	m1.insert(15);
	m1.insert(20);
	m1.insert(5);
	m1.insert(8);
	m1.insert(36);
    m1.insert(1);
    m1.insert(9);
    m1.display(cout);
    
    cout << "Search 5:" << ((m1.search(5))?"true":"false") << endl;
    cout << "Search 4:" << ((m1.search(4))?"true":"false") << endl << endl;
    
    m1.display(cout);
    cout << "Remove 5:" << ((m1.remove(5))?"true":"false") << endl;
    m1.display(cout);
    cout << "Remove 4:" << ((m1.remove(4))?"true":"false") << endl;
    m1.display(cout);
    
    BST m2(m1);
    cout << endl << "m2 created with copy constructor:" << endl;
    m2.display(cout);
    
    cout << endl;
    BST m3;
    m3.insert(6);
    m3.display(cout);
    m3=m1;
    cout << "m3 after the assignment operator:" << endl;
    m3.display(cout);
    
	return 0;
}