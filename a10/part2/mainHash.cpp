#include <iostream>
#include<cstring>
#include<fstream>
#include <ctime>
#include<cstdlib>
#include "hashTable.h"

using namespace std;
int hashFunction(itemType key) // Hash function for 1567
{
    int x =0;
    for(int i=0; i<key.length(); i++)
        x= x + (int)(key[i]);
    return x%1567;
}

int main()
{
	HashTable table(hashFunction ,1567); // hashTable with size 1567 and hash function above
    
    time_t start, end;
    double time;
    
   	ifstream file1;
    
    start = clock(); // starts the clock
    file1.open("iptree2.txt"); //opens file
    
    start = clock();
	if( file1.is_open() ) // If file is open
    {
        string line;
        
		while( getline(file1,line)) // reads lines
			table.insert(line); // inserts lines to the table
	}
    
	cout << endl << "-Load Factor: " << table.loadFactor() << "  Average Lenght: " << table.avgLenght() << endl;
    
    end = clock();
    time = (end-start) / (double)CLOCKS_PER_SEC;
    cout << "Time to read 'iptree2.txt': " << time << endl << endl;
    
    
	HashTable goodTable(hashFunction ,1567), badTable(hashFunction ,1567);
	ifstream file2;
    ofstream goodFile, badFile;
    
    start = clock(); // starts the clock
    file2.open("ddos2.txt"); //opens file
    goodFile.open ("good.txt"); //opens file
    badFile.open ("bad.txt"); //opens file
    
	if( file2.is_open() ) // If file is open
    {
		string line;
		while( getline(file2,line)) // reads line
		{
			if(table.find(line)) // if table has the line
            {
                badTable.insert(line); // inserts it to the bad table
				badFile << line << "\n"; // writes it to ile
            }
            
			else // if table doesnt have the line
            {
                goodTable.insert(line); // inserts it to the good table
				goodFile << line << "\n"; // writes it to file
            }
		}
	}
    
	cout << "-Load Factor: " << goodTable.loadFactor() << "  Average Lenght: " << goodTable.avgLenght() << endl;

	cout << "-Load Factor: " << badTable.loadFactor() << "  Average Lenght: " << badTable.avgLenght() << endl;
    
    end = clock();
    time = (end-start) / (double)CLOCKS_PER_SEC;
    cout << "Time to read 'ddos2.txt': " << time << endl << endl;
    
    goodFile.close();
    badFile.close();
	file1.close();
	file2.close();
	return 0;
}
