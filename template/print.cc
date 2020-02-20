#include <iostream>
using std::cout;
using std::endl;

template<class T>
void print(T t)
{
    cout << t << endl;
}
template<class T,class... Args>
void print(T t, Args ...args)
{
    cout << t << endl;
    print(args...);
}
int main()
{
    const char* p = "hello,wrold";
    print(1, p, "shenzhen");
    return 0;
}

