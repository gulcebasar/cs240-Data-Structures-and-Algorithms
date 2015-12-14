#ifndef PRINTER
#define PRINTER

#include"pqueue.h"
#include"job.h"

class Printer
{
public:
    Printer();
    // default constructor of printer
    // sets done jobs to 0
    
    void addJob(Job& j);
    // Adds a job to the waiting list
    
    int print();
    // a function to use the printer
    
    bool busy();
    // returns if printer is busy or not
    
    int waitTime();
    // returns the waiting time of printer
    
    int getCurJobNum();
    // Gets the number of current job
    
    int getJobDone();
    // gets the number of done jobs
    
private:
    int jobsDone;
    Job curJob;
    P_Queue waiting;
};

#endif