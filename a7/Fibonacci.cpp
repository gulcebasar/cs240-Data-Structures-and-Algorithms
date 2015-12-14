#include <iostream>
#include <ctime>

using namespace std;

long Fibonacci(int n);
long rFibonacci(int n);

int main()
{
    time_t start, end;
    int n;
    double time;
    
    cout << "Enter a number:";
    cin >> n;
    
    start = clock();
    cout << endl << "Fibonacci: " << Fibonacci(n);
    end = clock();
    time = (end-start) / (double)CLOCKS_PER_SEC;
    cout << "     -Execution time: "<< time << " seconds" << endl;
    /*
    start = clock();
    cout <<  "rFibonacci: " << rFibonacci(n);
    end = clock();
    time = (end-start) / (double)CLOCKS_PER_SEC;
    cout << "     -Execution time: "<< time << " seconds" << endl;
    */
    return 0;
}

long Fibonacci(int n)
{
    long num1=0, num2=1, num3; // first num=0; second num=1; third num currently empty
    
    if ( n < 2 )
        return n;
    for ( int i=0 ; i<=n-2 ; i++ )
    {
        num3 = num1+num2;
        num1 = num2;
        num2 = num3;
    }
    return num3;
}

long rFibonacci(int n)
{
    if ( n < 2 )
        return n;
    else
        return rFibonacci(n - 1) + rFibonacci(n - 2);
}
