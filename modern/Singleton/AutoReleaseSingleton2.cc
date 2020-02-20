#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(_pInstance == nullptr){
            _pInstance = new Singleton();
            atexit(destroy);
        }
        return _pInstance;
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
};


Singleton * Singleton::_pInstance = nullptr;

int main()
{
    Singleton * p = Singleton::getInstance();
    p->print();
    return 0;
}

