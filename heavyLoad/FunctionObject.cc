#include <iostream>
using std::cout;
using std::endl;

struct FunctionObject
{
    int operator()(int x, int y)
    {
        ++_count;
        return x + y;
    }

    int operator()(int x, int y, int z)
    {
        return x * y * z;
    }

    int getCount() const {  return _count;  }

private:
    int _count = 0;
};
int main()
{
    FunctionObject fo;
    cout << fo(1, 2) << endl;
    cout << fo(3, 4) << endl;
    cout << fo.getCount() << endl;
    return 0;
}

