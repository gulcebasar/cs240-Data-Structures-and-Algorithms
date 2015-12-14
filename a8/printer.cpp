#include<iostream>
#include<cassert>
#include<sstream>
#include<fstream>
#include"pqueue.h"
#include"printer.h"
#include"job.h"

using namespace std;

Printer::Printer()
{
    jobsDone=0; // sets jobsDone to 0
}

int Printer::getJobDone()
{
    return jobsDone; // returns jobsDone
}

int Printer::waitTime()
{
    return waiting.length(); // Returns the lenght of the waiting list
}

int Printer::getCurJobNum()
{
    return curJob.getJobNum(); // Returns the number of the current job
}

void Printer::addJob(Job& j)
{
    waiting.addItem(j); // Adds the job to the waiting list
}

int Printer::print()
{
    int num=0; // sets num to 0
    
    if( !(this->busy()) && waitTime()!=0 ) // If the printer is not busy and there are waiting jobs
    {
        curJob = waiting.getHighest(); // prints the job with highest priority
        waiting.removeHighest(); // removes the job with highest priority
        
        num = curJob.getJobNum(); // num is current jobs Number
    }
    else if( this->busy() )
    {
        num = curJob.getJobNum(); // num is current jobs Number
    }
    
    if( curJob.getPageNum() <= 5 && curJob.getPageNum() > 0 )// If there are less than 5 pages remaining
    {
        curJob.makeEmpty(); // makes the curJob empty
        jobsDone++; // Increases the done job number
    }
    
    else
        curJob.setPageNum( curJob.getPageNum() - 5 ); // pageNum is pageNum-5
    
    return num; // returns the number
}


bool Printer::busy()
{
    if (curJob.getJobNum() == 0) return false; // if curJobs num is 0, it means thar it is empty
    return true;
}
