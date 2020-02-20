#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base()
    {   cout << "Base()" << endl;}
    Base(double base)
    : _base(base)
    {   cout << "Base(double)" << endl;   }

    double getBase() const
    {   return _base;   }
private:
    double _base;
};

class Derived
: public Base
{
public:

    void display() const
    {
        cout << "_base = " << getBase() << endl;
        cout << "_derived = " << _derived << endl;
    }

private:
    double _derived;
};
int main()
{
    Derived d1;
    d1.display();
    return 0;
}

