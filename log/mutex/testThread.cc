#include "mutexLock.h"
#include "condition.h"
#include <iostream>
using std::cout;
using std::endl;

int getTicket = 100;
bool flag = true;
wd::MutexLock mutex;
wd::Condition condition(mutex);

void * threadFunc1(void * arg)
{
    int cnt = 20;
    while(cnt--)
    {
        {
            wd::MutexLockGuard aotolock(mutex);
            if(false == flag){
                condition.wait();
            }
            --getTicket;
            cout << "sub thread" << pthread_self() << ":"
                << "getTicket = " << getTicket << endl;
            if(flag){
                flag = false;
            }
        }
        condition.notify();
    }
    return NULL;
}

void * threadFunc2(void * arg)
{
    int cnt = 20;
    while(cnt--)
    {
        {
            wd::MutexLockGuard aotolock(mutex);
            if(true == flag){
                condition.wait();
            }
            --getTicket;
            cout << "sub thread" << pthread_self() << ":"
                << "getTicket = " << getTicket << endl;
            if(!flag){
                flag = true;
            }
        }
        condition.notify();
    }
    return NULL;
}
int main()
{
    pthread_t pthid1, pthid2;
    pthread_create(&pthid1, NULL, threadFunc1, NULL);
    pthread_create(&pthid2, NULL, threadFunc2, NULL);

    pthread_join(pthid1,NULL);
    pthread_join(pthid2,NULL);
    return 0;
}

