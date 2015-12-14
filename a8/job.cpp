#include<iostream>
#include<cassert>
#include"job.h"

using namespace std;

Job::Job() // Sets all elements to 0, creates an empty job
{
    Jtime=0;
    priority=0;
    pageNum=0;
    jobNum=0;
}

Job::Job(int t, int pri, int pNum, int jNum) // Sets all elements to given values
{
    Jtime=t;
    priority=pri;
    pageNum=pNum;
    jobNum=jNum;
}

Job::Job(const Job& j) // Copy constructor
{
    Jtime=j.getTime();
    priority=j.getPriority();
    pageNum=j.getPageNum();
    jobNum=j.getJobNum();
}

Job Job::operator=(const Job& j) // Assignment operator
{
    Jtime=j.getTime();
    priority=j.getPriority();
    pageNum=j.getPageNum();
    jobNum=j.getJobNum();
    
    return *this;
}

int Job::getTime() const // function to get time
{
    return Jtime;
}

int Job::getPriority() const // function to get priority
{
    return priority;
}

int Job::getPageNum() const // function to get page number
{
    return pageNum;
}

int Job::getJobNum() const // function to get job number
{
    return jobNum;
}

void Job::setPageNum(int num) // function to change page number
{
    pageNum=num;
}

void Job::makeEmpty() // Sets all elements to 0
{
    Jtime=0;
    priority=0;
    pageNum=0;
    jobNum=0;
}

void Job::display() // displays the members of job
{
    cout << "#" << jobNum << "  time:" << Jtime << "  priority:" << priority << "  pageNum:" << pageNum << endl;
}
