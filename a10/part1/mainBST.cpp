#include <iostream>
#include<cstring>
#include<fstream>
#include <ctime>
#include "bst.h"

using namespace std;

int main()
{
	BST tree;
    time_t start, end;
    double time;
    
   	ifstream file1;
    
    start = clock(); // starts the clock
    file1.open("iptree2.txt"); //opens file
    
    start = clock();
	if( file1.is_open() ) // If file is open
    {
        string line;
		while( getline(file1,line)) // reads line
			tree.insert(line); // inserts lines to the tree
	}
    
	//tree.display(cout);
	cout << endl << "-Size: " << tree.size() << "  Height: " << tree.height() << endl;
    end = clock();
    time = (end-start) / (double)CLOCKS_PER_SEC;
    cout << "Time to read 'iptree2.txt': " << time << endl << endl;
    
    
	BST goodTree, badTree;
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
			if(tree.search(line)) // if tree has the line
            {
                badTree.insert(line); // inserts it to the bad tree
				badFile << line << "\n"; // writes it to file
            }
            
			else // if tree doesnt have the line
            {
                goodTree.insert(line); // inserts it to the good tree
				goodFile << line << "\n"; // writes it to file
            }
		}
	}
    
	cout << "-Good Tree's Size: " << goodTree.size() << endl;
	cout << "-Bad Tree's Size: " << badTree.size() << endl;
    end = clock();
    time = (end-start) / (double)CLOCKS_PER_SEC;
    cout << "Time to read 'ddos2.txt': " << time << endl << endl;
    
    goodFile.close();
    badFile.close();
	file1.close();
	file2.close();
	return 0;
}
