#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool Search(int* array, int size, int num);
bool bSearch(int* array, int size, int num);

int main()
{
    srand(time(0));
    
    time_t start, end;
    int size, num;
    double time;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int array[size];
    for (int i=0 ; i<size ; i++ )
        array[i] = ( rand()%100 ) + 1 ; // Random number between 100 and 1

    start = clock();   
    for(int i=0; i<size; i++)
   	Search(array, size, array[i]);
    end = clock();
    time = (end-start) / (double)CLOCKS_PER_SEC;
    cout << "Search execution time: "<< time << " seconds" << endl;

    sort(array, array + size);

    start = clock();
    for(int i=0; i<size; i++)
	bSearch(array, size, array[i]);  
    end = clock();
    time = (end-start) / (double)CLOCKS_PER_SEC;
    cout << "bSearch execution time: "<< time << " seconds" << endl;

    return 0;
}

bool Search(int* array, int size, int num)
{
    for (int i = 0; i < size; i++) {
        if ( *(array+i) == num )
            return true;
    }
    return false;
}

bool bSearch(int* array, int size, int num)
{
    int min=0, max=size, mid;
    while (max >= min){
        mid = (min + max) / 2;
        
        if ( *(array+mid) < num )
            min = mid + 1;
        else if ( *(array+mid) > num )
            max = mid - 1;
        else
            return true; 
    }

    if (*(array+min) == num)
        return true;
    return false;
}


