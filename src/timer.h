#ifndef _TIMER_H_
#define _TIMER_H_

class Timer
{
  private:
    int stampTime;
  public:
    Timer();
    ~Timer();
    
    void stamp();
    int msSinceStamp() const;
};

#endif

