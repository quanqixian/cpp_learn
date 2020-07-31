#include "Thread.h"
Thread::Thread()
{

}

bool Thread::start()
{
    if(isRunning == false)
    {
        /* 注意这里传入了this指针 */
        if(pthread_create(&threadID, NULL, threadProcess, this) != 0)
        {
            cout << __FILE__<<":"<<__LINE__<<" pthread_create failed!" << endl;
            return false;
        }
        isRunning = true;
    }
    return isRunning;
}

bool Thread::stop()
{
    void *thrdRet = NULL;

    if(isRunning)
    {
        isRunning = false;
        pthread_join(threadID, &thrdRet);
    }

    return !isRunning;
}

void * Thread::threadProcess(void * arg)
{
    /* 根据不同的实例指针调用对应的成员函数 */
    Thread * pthis = static_cast<Thread*>(arg);
    pthis->run();
}

Thread::~Thread()
{
    stop();
}