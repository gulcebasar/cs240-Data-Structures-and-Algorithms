#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include "bst.h"

using namespace std;

void fillArray(int* arr);

int main()
{
    srand(time(0));
    
    int arr1[1000], arr2[1000], arr3[1000], arr4[1000], arr5[1000];
    fillArray(arr1); fillArray(arr2); fillArray(arr3); fillArray(arr4); fillArray(arr5);
    
    cout << endl << " Array 1 : " << endl;
    BST tree1;
    for(int i=0; i<1000; i++)
        tree1.insert(arr1[i]);
    cout << "-Size: " << tree1.size() << endl;
    cout << "-Height: " << tree1.height() << endl;
    
    cout << endl << " Array 2 : " << endl;
    BST tree2;
    for(int i=0; i<1000; i++)
        tree2.insert(arr2[i]);
    cout << "-Size: " << tree2.size() << endl;
    cout << "-Height: " << tree2.height() << endl;
    
    cout << endl << " Array 3 : " << endl;
    BST tree3;
    for(int i=0; i<1000; i++)
        tree3.insert(arr3[i]);
    cout << "-Size: " << tree3.size() << endl;
    cout << "-Height: " << tree3.height() << endl;
    
    cout << endl << " Array 4 : " << endl;
    BST tree4;
    for(int i=0; i<1000; i++)
        tree4.insert(arr4[i]);
    cout << "-Size: " << tree4.size() << endl;
    cout << "-Height: " << tree4.height() << endl;
    
    cout << endl << " Array 5 : " << endl;
    BST tree5;
    for(int i=0; i<1000; i++)
        tree5.insert(arr5[i]);
    cout << "-Size: " << tree5.size() << endl;
    cout << "-Height: " << tree5.height() << endl;
    
    cout << endl << " Sorted Array 5 : " << endl;
    sort(arr5, arr5+1000);
    BST tree6;
    for(int i=0; i<1000; i++)
        tree6.insert(arr5[i]);
    cout << "-Size: " << tree6.size() << endl;
    cout << "-Height: " << tree6.height() << endl;
    
    return 0;
}

void fillArray(int* arr)
{
    for(int i=0; i<1000; i++)
    {
        arr[i]= ( rand()%10000 ) + 1;
    }
}