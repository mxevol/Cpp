#include <iostream>
using std::cout;
using std::endl;

template <class T1, class T2>
T2 multiply(T1 x, T2 y)
{
    return x * y;
}

template <class T1, int number = 10>
T1 multiply(T1 x)
{
    return x * number;
}


int main()
{
    int x = 2;
    double y = 2.22;
    cout << "multiply(T1, T2) = " << multiply(x, y) << endl;
    cout << "multiply(T1) = " << multiply(y) << endl;
    cout << "multiply<T1, int>(T1)" << multiply<double, 100>(y) << endl;
    return 0;
}

