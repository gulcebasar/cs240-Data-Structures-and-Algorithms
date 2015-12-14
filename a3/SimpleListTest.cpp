#include <iostream>
#include "SimpleList.h"
#include "Fraction.h"

using namespace std;

void func1(SimpleList l){ // func1 takes a SimpleList
    // func1 uses the copy constructor to creates l
    cout << "   In func1:" << endl;
    
    Fraction f; // Creates a Fraction
    l.insert(3, f); // Uses insert to add f to index 3
    cout << "   insert(3, f): " << l ;
    
    l.remove(1); // Removes the Fraction in index 1
    cout << "   remove(1): " << l ;
    
    l.makeEmpty(); // Uses makeEmpty() to emty the list
    cout << "   makeEmpty(): " << l ;
    // func1 uses destructor in the end to delete l
}

void func2(SimpleList& l){ // func2 takes a SimpleList &
    // func2 takes the l1 from main as l for the function
    cout << "   In func1:" << endl;
    
    Fraction f; // Creates a Fraction
    l.insert(3, f); // Uses insert to add f to index 3
    cout << "   insert(3, f): " << l ;
    
    l.remove(1); // Removes the Fraction in index 1
    cout << "   remove(1): " << l ;
    
    l.makeEmpty(); // Uses makeEmpty() to emty the list
    cout << "   makeEmpty(): " << l ;
}

int main()
{
	SimpleList l1; // Creates a SimpleList l1
    
    Fraction f1(3,5); // Creates Fractions to add l1
	Fraction f2(1,2);
    Fraction f3(4,6);
    Fraction f4(1,8);
    Fraction f5(5,2);
    
	l1.append(f1); // Adds Fractions to l1
	l1.append(f2);
	l1.append(f3);
	l1.append(f4);
    l1.append(f5);
    
    cout << endl << "List1: " << l1 << endl;
    
    SimpleList l2(l1); // Creates l2 with the copy contructor
    cout << "List2, created with the copy constructor: " << l2 ;
    
    SimpleList l3; // Creates l3
    cout << endl << "List3: " << l3 ;
    l3=l1; // Uses = operator for l3
    cout << "List3 after '=': " << l3 << endl;
    
    {
        cout << "List4 created in the scope" << endl ;
        SimpleList l4; // Creates l4
        cout << "List4: " << l4 ;
    }
    cout << "List4 is deleted at the end of the scope" << endl ;
    
    
	cout << endl << "List1 before func1: " << l1 ; // Prints l1 before func1
    func1(l1); // Calls func1
    cout << "List1 after func1: " << l1 ; // Prints l1 after func1
    
    
    cout << endl << "List1 before func2: " << l1 ; // Prints l1 before func2
    func2(l1); // Calls func2
    cout << "List1 after func2: " << l1 << endl; // Prints l1 after func2
    
    // uses destructor in the end to delete l1, l2 and l3

	return 0;
}
