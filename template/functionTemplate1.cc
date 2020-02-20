#include <string.h>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;


template <typename T>
T add(T x, T y)
{
    return x + y;
}

int main()
{
    int x1 = 3, x2 = 4;
    double x3 = 3.13, x4 = 3.14;
    string s1 = "hello", s2 = "world";
    char c1 = 'a', c2 = 1;
    cout << "add(x1, x2) = " << add(x1, x2) << endl;
    cout << "add(x3, x4) = " << add(x3, x4) << endl;
    cout << "add(s1, s2) = " << add(s1, s2)<< endl;
    cout << "add(c1, c2) = " << add(c1, c2) << endl;

    return 0;
}

