#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(double data)
    : _data(data)
    {   cout << "Base(double data)" << endl;    }
    virtual
    void print() const
    {   cout << "Base::_data = " << _data << endl;}
private:
    double _data;
};

class Derived
: public Base
{
public:
    Derived(double base, double derived)
    : Base(base)
    , _data(derived)
    {   cout << "Derived(double, double)" << endl;}
    
    void print() const
    {   cout << "Derived:: _data = " << _data << endl;}
private:
    double _data;
};
int main()
{
    Base b1(33.33);
    b1.print();
    Derived d1(11.11, 12.12);
    d1.print();
    b1 = d1;
    b1.print();
    cout << endl;
    Base * pbase = &d1;
    pbase->print();
    return 0;
}

