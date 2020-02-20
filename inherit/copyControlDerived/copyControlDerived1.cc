#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(const char * base)
    : _base(new char[strlen(base) + 1]())
    {
        cout << "Base(const char*)" << endl;
        strcpy(_base, base);
    }

    Base(const Base & rhs)
    : _base(new char[strlen(rhs._base) + 1]())
    {
        cout << "Base(const Base & rhs)" << endl;
        strcpy(_base, rhs._base);
    }

    Base & operator=(const Base & rhs)
    {
        cout << "Base & operator=(const Base & rhs)" << endl;
        if(this != &rhs){
            delete [] _base;
            _base = new char[strlen(rhs._base) + 1]();
            strcpy(_base, rhs._base);
        }
        return *this;
    }

    ~Base()
    {
        if(_base)
            delete [] _base;
    }

private:
    char * _base;
};

class Derived
: public Base
{
public:
    Derived(const char * base)
    : Base(base)
    {
        cout << "Derived()" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

};
int main()
{
    Derived d1("hello");
    Derived d2(d1);
    d1 = d2;
    return 0;
}

