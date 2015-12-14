#include<cstring>
#include<iostream>
#include<cstdlib>
#include<utility>
#include<vector>
#include"map.h"

using namespace std;

Map::Map() { } // Constructor of map
// It is empty since I used a vector. I just showed it here because it was in the list of wanted functions
    
void Map::addPair(keyType key, valueType value) // A function to add a pair to map
{
    map.push_back(make_pair(key,value)); // Makes a pair from two parameters and pushs it to the vector
}
    
bool Map::findPair(keyType key) // A function to see if the map has the key
{
    for (int i=0; i<map.size(); i++) // Searches the map
        if(map.at(i).first == key) // If the pairs first is the key
            return true; // returns true
    return false; // returns false if the key is not found
}
    
valueType* Map::getValue(keyType key) // A function to get the value of the key
{
    for (int i=0; i<map.size(); i++) // Searches the map
        if(map.at(i).first == key) // If the pairs first is the key
            return &map.at(i).second; // returns the value of the key
    return NULL; // returns false if the key is not found
}

/*
// function to print value
// I didn't erase this function since it can be used to test map
ostream& operator<<(ostream &out, Value& value){
	out << "-" << value.password << (value.si?" -true":" -false");
    return out; // returns out
}
*/