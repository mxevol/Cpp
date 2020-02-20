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
    Derived(const char * base, const char * derived)
    : Base(base)
    , _derived(new char[strlen(derived) + 1]())
    {
        cout << "Derived(const char *, const char *)" << endl;
        strcpy(_derived, derived);
    }

    Derived(const Derived & rhs)
    : Base(rhs)
    , _derived(new char[strlen(rhs._derived) + 1]())
    {
        cout << "Derived(const Derived & rhs)" << endl;
        strcpy(_derived, rhs._derived);
    }
    
    Derived & operator=(const Derived & rhs)
    {
        cout << "Derived & operator=(const Derived & rhs)" << endl;
        if(this != &rhs){
            Base::operator=(rhs);
            delete [] _derived;
            _derived = new char[strlen(rhs._derived) + 1]();
            strcpy(_derived, rhs._derived);
        }
        return *this;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

private:
    char * _derived;
};
int main()
{
    Derived d1("hello","world");
    Derived d2(d1);
    d1 = d2;
    return 0;
}

