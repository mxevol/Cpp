#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {   cout << "Point(int ,int)" << endl;}

    void print() const
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }
    friend double distance(const Point & lhs, const Point & rhs);

private:
    int _ix;
    int _iy;
};

double distance(const Point & lhs, const Point & rhs)
{
    return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) +
                (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy)); 
}
int main()
{
    Point p1(1, 2);
    Point p2(11, 12);
    cout << distance(p1, p2) << endl;
    return 0;
}

