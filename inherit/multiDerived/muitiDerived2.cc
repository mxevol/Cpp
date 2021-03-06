#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    A() {   cout << "A()" << endl;}
    ~A() {  cout << "~A()" << endl;}

    void print() const
    {   cout << "A::print()" << endl;}
};
class B
{
public:
    B() {   cout << "B()" << endl;}
    ~B() {  cout << "~B()" << endl;}

    void print() const
    {   cout << "B::display()" << endl;}
};
class C
{
public:
    C() {   cout << "C()" << endl;}
    ~C() {  cout << "~C()" << endl;}

    void print() const
    {   cout << "C::show()" << endl;}
};

class D
: public A
, public B
, public C
{
public:
    D() {   cout << "D()" << endl;}
    
    void print() const
    {   cout << "D::print()" << endl;}
    ~D() {   cout << "~D()" << endl;}

};
int main()
{
    D d;
    d.print();
    d.print();
    d.print();
    return 0;
}

