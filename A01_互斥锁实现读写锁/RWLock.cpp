#include <mutex>
class RWLock
{
public:
    RWLock();
    void readLock();
    void readUnlock();
    void writeLock();
    void writeUnlock();
private:
    mutex read_mtx;
    mutex write_mtx;
    int read_cnt; /* 已加读锁个数 */
};

RWLock::RWLock() : read_cnt(0)
{
}

void RWLock::readLock()
{
    read_mtx.lock();

    if (++read_cnt == 1)
    {
        write_mtx.lock();
    }

    read_mtx.unlock();
}

void RWLock::readUnlock()
{
    read_mtx.lock();

    if (--read_cnt == 0)
    {
        write_mtx.unlock();
    }

    read_mtx.unlock();
}

void RWLock::writeLock()
{
    write_mtx.lock();
}

void writeUnlock()
{
    write_mtx.unlock();
}
