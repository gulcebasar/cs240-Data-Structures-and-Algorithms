#include<iostream>
#include<sstream>
#include <fstream>
#include<cmath>
#include<cstring>
#include "Stack.h"

using namespace std;

void stFile(string filename);
StackElement operate(StackElement x, StackElement y, string c);

int main()
{
    cout << endl ;
    
    stFile("test.txt");
}

void stFile(string filename)
{
    Stack solutions;
    int lineCounter=0;
    
    ifstream file1;
    file1.open(filename.c_str());
    
    if( file1.is_open() )
    {
        bool error=false;
        string line;
        
        Stack solve;
        StackElement num1, num2;
        
        for( int i=0 ; getline(file1,line) ; i++)
        {
            error=false;
            lineCounter++;
            istringstream iss(line);
            
            string c;
            
            do{
                
                iss >> c;
                
                if( c.compare("+")!=0 && c.compare("-")!=0 && c.compare("*")!=0 && c.compare("/")!=0 && c.compare("#")!=0 )
                    solve.push( atoi( c.c_str() ) );

                
                else if( c.compare("+")==0 || c.compare("-")==0 || c.compare("*")==0 || c.compare("/")==0 )
                {
                    if ( solve.size()<2 )
                    {
                        error=true;
                        break;
                    }
                    
                    num2 = solve.top();
                    solve.pop();
                    
                    num1 = solve.top();
                    solve.pop();
                    
                    solve.push( operate( num1, num2, c ) );
                }
                
            }while( c.compare("#")!=0 );
            
            if(solve.size()>1)
                error=true;
            
            if(error)
                cout << " -Error on line " << lineCounter << "   : " << line << endl;
            else
                solutions.push( solve.top() );
            while( !solve.empty() )
                solve.pop();
        }
    }
    
    file1.close();
    
    cout << endl << "Solutions of line " << lineCounter << " to line 1" << endl;
    solutions.display(cout);
}

StackElement operate(StackElement x, StackElement y, string c)
{
    StackElement a=0;
    
    if( c.compare("+")==0 )
        a=x+y;
    
    else if( c.compare("-")==0 )
        a=x-y;
    
    else if( c.compare("*")==0 )
        a=x*y;
    
    else if( c.compare("/")==0 )
        a=x/y;
    return a;
}
