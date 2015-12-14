#include <iostream>
#include "Poly.h"

using namespace std;

int main(){
    Poly p;
    
cout << "Poly p:  empty=" << (p.empty()?"true":"false") 
            << "  degree= " << p.degree() << endl;
cout << endl;

    p.appendTerm(2,0);
    p.appendTerm(3,1);
    p.appendTerm(1,3);
    p.appendTerm(3,4);
    p.appendTerm(2,6);
    
cout << "Poly p after append:  empty=" << (p.empty()?"true":"false") 
            << "  degree= " << p.degree() << endl;
p.display(cout);
    cout << endl;
    
    Poly p2(p);
cout << "Poly p2:  empty=" << (p.empty()?"true":"false") 
            << "  degree= " << p.degree() << endl;
    p2.display(cout);
    cout << endl;
    
    Poly p3;
    p3.appendTerm(1,2);
    p3.appendTerm(5,3);
    p3.appendTerm(5,4);
cout << "Poly p3:  empty=" << (p.empty()?"true":"false") 
            << "  degree= " << p.degree() << endl;
    p3.display(cout);
    cout << endl;
    
    Poly p4= (p+p3);
cout << "Poly p4=p+p3:  empty=" << (p.empty()?"true":"false") 
            << "  degree= " << p.degree() << endl;
    cout << "p: ";
    p.display(cout);
    cout << "p3: ";
    p3.display(cout);
    cout << "p+p3: ";
    p4.display(cout);
    cout << endl;
    
    p3=p;
cout << "Poly p3 after p3=p:  empty=" << (p.empty()?"true":"false") 
            << "  degree= " << p.degree() << endl;
    cout << "p: ";
    p.display(cout);
    cout << "p3: ";
    p3.display(cout);
    cout << endl;
    
    cout << "Evaluate p for 0: " << p.evaluate(0) << endl;
    cout << "Evaluate p for 1: " << p.evaluate(1) << endl;
    cout << "Evaluate p for 2: " << p.evaluate(2) << endl;

    return 0;
}
