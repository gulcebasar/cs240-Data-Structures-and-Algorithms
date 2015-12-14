#ifndef JOB
#define JOB

class Job{
public:
    Job();
    // default constructor to make an empty job
    
    Job(int t, int pri, int pNum, int jNum);
    // constructor to make a job with the specified input
    
    Job(const Job& j);
    // copy constructor
    
    Job operator=(const Job& j);
    // assignment operator
    
    int getTime() const;
    // function to get time
    
    int getPriority() const;
    // function to get priority
    
    int getPageNum() const;
    // function to get page number
    
    int getJobNum() const;
    // function to get job number
    
    void setPageNum(int num);
    // function to change page number
    
    void makeEmpty();
    // function to make job empty
    
    void display();
    // function to display job (for P_Queue)
    
private:
    int Jtime; // jobs time interval
    int priority; // jobs priority
    int pageNum; // jobs number of pages
    int jobNum; // jobs number
};

#endif