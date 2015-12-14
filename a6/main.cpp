#include "Fraction.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <deque> 
#include <algorithm>

using namespace std;


template <typename T>
double average(T obj1, T obj2)
{
    T sum = obj1 + obj2; // Sun od objects
    return sum/2.0; // Divides sum by 2
}

template <typename T>
bool order( vector<T> vec1 )
{
    for( int i=0; i<vec1.size()-1; i++) // A loop from 0 to vectors size
    {
        if( vec1.at(i)+1 != vec1.at(i+1) ) // If vector(i)+1 != vector(i+1)
            return false;
    }
    return true; // If vector(i)+1 = vector(i+1)
}


int main()
{
    cout << "Average of 3 and 5 is: " << average(4,5) << endl; // average int
    cout << "Average of 4.2 and 5.7 is: " << average( 4.2 , 5.7 ) << endl; // average double
    Fraction a(8,9) , b(1,3);
    cout << "Average of 8/9 and 1/3 is: " << average(a,b) << endl << endl; // average fraction
    
    vector<int> vecInt(6); // Int vector
    for(int i=0; i<6 ; i++)
        vecInt.at(i)=i; // ordered vector
    
    cout << "VecInt: ";
    for(int i=0; i<6 ; i++) // prints vector
        cout << vecInt.at(i) << " ";
    cout << " Order? " << (order(vecInt)?"true":"false") << endl;  // order int
    
    vecInt.at(3)=8; // not ordered
    cout << "VecInt: ";
    for(int i=0; i<6 ; i++)  // prints vector
        cout << vecInt.at(i) << " ";
    cout << " Order? " << (order(vecInt)?"true":"false") << endl;  // order int
    
    vector<Fraction> vecFrac(6); // Fraction vector
    for(int i=0; i<6 ; i++)
    {
        
        Fraction f( (2+(3*i)) , 3 );
        vecFrac.at(i)=f;  // ordered vector
    }
    
    cout << "VecFrac: ";
    for(int i=0; i<6 ; i++)  // prints vector
        cout << vecFrac.at(i) << " ";
    cout << " Order? " << (order(vecFrac)?"true":"false") << endl; // order fraction
    
    Fraction x(20,8);
    vecFrac.at(3)=x;  // not ordered
    cout << "VecFrac: ";
    for(int i=0; i<6 ; i++)  // prints vector
        cout << vecFrac.at(i) << " ";
    cout << " Order? " << (order(vecFrac)?"true":"false") << endl;  // order fraction
    
    cout << endl;
    
    srand(time(0));
    int vecCount;
    
    vector<int> vec(100);// a vector with size 100
    
    for (int i=0; i<vec.size(); i++) // Fill vector
        vec.at(i) = ( rand()%90 ) + 10 ; // random number between 10 and 99
    
    vector<int>::iterator it;
    
    cout << "Vector:" << endl;
    for( it=vec.begin(); it!=vec.end(); it++) // Print vector
        cout << (*it) << "  ";
    cout << endl;
    
    it = max_element( vec.begin() , vec.end() ); // max values iterator
    int maxValue = (*it); // max value
    cout << "Largest value of the vector is: " << maxValue ;
    vecCount = count( vec.begin() , vec.end() , maxValue ); // number of max value in vector
    cout << " it appears " << vecCount << " times." << endl;
    
    it = min_element( vec.begin() , vec.end() ); // min values iterator
    int minValue = (*it); // min value
    cout << "Smallest value of the vector is: " << minValue ;
    vecCount = count( vec.begin() , vec.end() , minValue ); // number of max value in vector
    cout << " it appears " << vecCount << " times." << endl;
    
    it = find( vec.begin() , vec.end() , 36 ); // iterator to value 36
    if( it == vec.end() ) // if it is the vec.end() 36 doesnt appear
        cout << "36 doesn't apper in vector" << endl;
    else // else 36 appears
        cout << "36 appears in vector" << endl;
    
    std::vector<int> unqVec(100); // unique vector
    for (int i=0; i<vec.size(); i++) // uncVec is equal to vec
        unqVec.at(i) = vec.at(i) ;
    
    sort( unqVec.begin() , unqVec.end() ); // sorted version of vector
    
    int unique = 1; //incase we have only one element
    for(int i = 0; i < unqVec.size()-1 ; i++)
    {
        if( unqVec.at(i) != unqVec.at(i+1) ) // if value after itself is not the same increases unique
            unique++;
    }
    
    cout << "Number of unique numbers is: " << unique << endl << endl; // num of unique numbers
    
    return 0;
}

