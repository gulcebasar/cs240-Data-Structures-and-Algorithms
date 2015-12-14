#ifndef MAP
#define MAP
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<utility>
#include <vector>

using namespace std;

// definition of class Value to use in main
class Value{
    //friend ostream& operator<<(ostream&, Value& value);
    // function to print value
    // I didn't erase this function since it can be used to test map
    
public:
    Value(string i1, bool i2) // constructor of value with two parameters
    {
        password=i1; // sets password to first parameter
        si=i2; // sets si to second parameter
    };
    
    string password;
    bool si;
};

// Map.h starts here
typedef string keyType; // keyType is string
typedef Value valueType; // valueType is the class Value
typedef pair<keyType, valueType> pairType; // pairType has a pair of keyType and valueType

class Map{
public:
    Map();
    // Constructor of map
    
    void addPair(keyType key, valueType value);
    // A function to add a pair to map
    
    bool findPair(keyType key);
    // A function to see if the map has the key
    
    valueType* getValue(keyType key);
    // A function to get the value of the key
    
private:
    vector<pairType> map; // a vector to hold pairs
};
#endif


