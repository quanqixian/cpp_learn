#include "Thread.h"
#include <unistd.h>
class TesetThread :public Thread
{
    void run()
    {
        while(isRunning())
        {
            cout<<"hello"<<endl;
            sleep(1);
        }
    }
};
int main(int argc, const char *argv[])
{
    TesetThread t;
    t.start();
    while(true)
    {
        sleep(1);
    }
    return 0;
}
