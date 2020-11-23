#ifndef _THREAD_H_
#define _THREAD_H_ 
#include <iostream>
#include <string>
#include <pthread.h>

using namespace std;

class Thread
{
private:
    volatile bool m_isRunning = false; /* 线程运行标志 */
    pthread_t threadID = 0;            /* 线程ID */
    static void* threadProcess(void * arg);
protected:
    virtual void run(void) = 0;        /* 由子类重写run函数 */
public:
    Thread();
    virtual ~Thread();
    bool start(void);
    bool stop(void);
    bool isRunning(void)const;
};
#endif
