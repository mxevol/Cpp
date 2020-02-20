#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(double base)
    : _base(base)
    {   cout << "Base(double)" << endl;}

    virtual
    void display() const
    {   cout << "_base = " << _base << endl;}

    void func1() const
    {
        this->display();
    }


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
    {   cout << "Derived(double, double)" << endl;}

    virtual
    void display() const
    {   cout << "derived = " << _derived << endl;}
private:
    double _derived;
};
int main()
{
    Derived d1(11.11, 12.12);
    d1.func1();
    return 0;
}

