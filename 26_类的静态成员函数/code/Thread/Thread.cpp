#include "Thread.h"
Thread::Thread()
{

}

bool Thread::start()
{
    if(m_isRunning == false)
    {
        /* 修改运行标志要在创建线程之前 */
        m_isRunning = true;

        /* 注意这里传入了this指针 */
        if(pthread_create(&threadID, NULL, threadProcess, this) != 0)
        {
            cout << __FILE__<<":"<<__LINE__<<" pthread_create failed!" << endl;
            m_isRunning = false;
        }
    }
    return m_isRunning;
}

bool Thread::stop()
{
    void *thrdRet = NULL;

    if(m_isRunning)
    {
        m_isRunning = false;
        pthread_join(threadID, &thrdRet);
    }

    return !m_isRunning;
}

bool Thread::isRunning()const
{
    return m_isRunning;
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
