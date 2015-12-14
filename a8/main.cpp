#include<iostream>
#include<cassert>
#include<sstream>
#include<fstream>
#include"pqueue.h"
#include"printer.h"
#include"job.h"

using namespace std;

void readFile(string filename, Job* jP, int& totalJobNum);
int calculateTotalTime(int totalJobNum, Job* jP);

int main()
{
    //SETUP PART
    int totalJobNum=0; // totalJobNum is 0
    Job jobArr[10]; // an array with the capacity of 10 jobs
    
    readFile( "in.txt" , jobArr , totalJobNum ); // reads a file into a job array and gets the total job number
    
    int jobNum=0; // jobNum is 0
    int prevJobDone=0; // number of previously completed jobs is 0
    double wait=0; // waiting time is 0
    
    int totalPageNum=0;
    for (int i=0; i<totalJobNum; i++)
        totalPageNum = totalPageNum + jobArr[i].getPageNum(); // adds the page numbers of all jobs
    
    int totalTime = calculateTotalTime( totalJobNum , jobArr ); // A function to calculate total time needed
    
    //PRINTING PART
    Printer p1; // a printer
    
    cout << "  time interval             current job            jobs waiting           jobs completed  " << endl;
    
    for( int i=0 ; i <= totalTime+1 ; i++ ) // totalTime+1 -> +1 is for the final statics
    {
        for (int j=0; j<totalJobNum; j++) // jobs
        {
            if ( jobArr[j].getTime() == i ) // checks jobs to see if they're submitted in the current time interval
            {
                p1.addJob(jobArr[j]); // increases time for printer with the submitted job
            }
        }
        jobNum=p1.print(); // print for that time interval
        
        cout<< "\t" << i << "\t\t\t" ; // prints time interval
        if(jobNum == 0)
            cout << "none"; // if jobnum is 0 job is empty
        else
            cout << jobNum; // prints the job number
        cout << "\t\t\t" << p1.waitTime() << "\t\t\t" << prevJobDone << endl; // prints the length of waitinglist and the number of previously done jobs
        
        wait = wait + p1.waitTime(); // adds waiting time to previous wait
        
        prevJobDone=p1.getJobDone(); // previously done jobs number is the number of completed jobs at the end of the loop
    }
    
    cout << endl << "Final Statistics:" << endl;
    cout << "Jobs printed: " << totalJobNum << endl; // total job num statics
    cout << "Pages printed: " << totalPageNum << endl; // total page num statics
    cout << "Average wait time: " << (wait/(double)totalJobNum) << endl << endl; // avarage wait is (wait time)/(total job number)
    
    return 0;
}

void readFile(string filename, Job* jP, int& totalJobNum)
{
    int time, pri, pNum, jNum; // to send to job
    
    ifstream file1;
    file1.open(filename.c_str());
    
    if( file1.is_open() )
    {
        string line;
        for( int i=0 ; getline(file1,line) ; i++) // gets a line from file
        {
            istringstream iss(line);
            
            jNum=i+1; // gives job a number
            iss >> time; // first one is time
            iss >> pri; // second one is priority
            iss >> pNum; // third one is page number
            
            jP[i] = Job( time , pri , pNum , jNum ); // adds a job with the lines input to array
            totalJobNum++; // increases total job number
        }
        file1.close();
    }
    else
        cout << "ERROR OPENING FILE" << endl;
}

int calculateTotalTime(int totalJobNum, Job* jP)
{
    int totalTime=0, index;
    
    for (int i=0; i<totalJobNum; i++) // a loop to check all jobs
    {
        if(jP[i].getTime() > totalTime )
        {
            totalTime=jP[i].getTime(); // totalTime is the time unit at which the last job is submitted
            index=i; // index is the last jobs index in array
        }
    }
    
    int page = jP[index].getPageNum(); // page is the page number of last submitted job
    while( page > 5 ) // it the last job has more then 5 pages
    {
        page = page-5;
        totalTime++; // increases total time
    }
    
    return totalTime;
}




