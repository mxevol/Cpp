#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    Computer(const char* brand, float price);
    Computer(const Computer & rhs);
    Computer & operator=(const Computer & rhs);
    ~Computer();
    void print();
private:
    char * _brand;
    float _price;

};

Computer::Computer(const char * brand, float price)
: _brand(new char[strlen(brand) + 1]())
, _price(price)
{
    cout << "Computer(const char *, float )" << endl;
    strcpy(_brand, brand);
}

Computer::Computer(const Computer & rhs)
: _brand(new char[strlen(rhs._brand) + 1]())
, _price(rhs._price)
{
    cout << "Computer(const Computer & rhs)" << endl;
    strcpy(_brand, rhs._brand);
}

Computer & Computer::operator=(const Computer & rhs)
{
    cout << "Computer & operator=(const Computer & rhs)" << endl;
    if(this != &rhs){
        delete [] _brand;
        _brand = new char[strlen(rhs._brand) + 1]();
        strcpy(_brand, rhs._brand);
        _price = rhs._price;
    }
    return *this; 
}
Computer::~Computer()
{
    delete [] _brand;
    cout << "~Computer()" << endl; 
}

void Computer::print()
{
    cout << "brand :" << _brand << endl
        << "price :" << _price << endl; 
}

void test0()
{
    Computer pc("xiaomi", 2999);
    pc.print();
}
void test1()
{
    Computer pc("huawei", 2000);
    printf("&pc = %p", &pc);
    Computer pc1 = pc;
    pc1.print();
    printf("&pc1 = %p", &pc1);
}
void test2()
{
    Computer pc("huawei", 2000);
    printf("&pc = %p\n", &pc);
    Computer pc1("xiaomi", 3000);
    printf("&pc1 = %p\n", &pc1);
    pc1 = pc;
    pc1.print();
    printf("&pc1 = %p\n", &pc1);
}
int main()
{
    test2();
    return 0;
}

