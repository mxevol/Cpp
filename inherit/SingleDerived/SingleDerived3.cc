#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
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
    Derived(double base, double derived)
    : Base(base)
    , _derived(derived)
    , _a(0)
    {   cout << "Derived(double, double)" << endl;}

    void display() const
    {
        cout << "_a = "  << _a.getBase() << endl;
        cout << "_base = " << getBase() << endl;
        cout << "_derived = " << _derived << endl;
    }

private:
    double _derived;
    Base _a;
};
int main()
{
    Derived d1(11.11, 22.22);
    d1.display();
    return 0;
}

