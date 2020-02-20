#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        pthread_once(&_once,init);
        return _pInstance;
    }

    static void init()
    {
        _pInstance = new Singleton();
        atexit(destroy);
    }

    static void destroy()
    {
        cout << "static void destroy()" << endl;
        if(_pInstance)
            delete _pInstance;
    }

    void print() const
    {   cout << "print()" << endl;  }


private:
    Singleton()
    {   cout << "Singleton()" << endl;  }
    ~Singleton()
    {   cout << "~Singleton()" << endl; }

private:
    static Singleton * _pInstance;
    static pthread_once_t _once;
};


Singleton * Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main()
{
    Singleton * p = Singleton::getInstance();
    p->print();
    return 0;
}

