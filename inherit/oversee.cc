#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(double data)
    : _data(data)
    {   cout << "Base(double data)" << endl;    }

    void print(int x) const
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
    Derived d1(11.11, 12.12);
    d1.print();
    return 0;
}

