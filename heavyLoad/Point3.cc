#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;
class Line
{
public:
    double distance(const Point & lhs, const Point & rhs);
    void setPoint(Point & pt, int ix, int iy);
};
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
    friend Line;

private:
    int _ix;
    int _iy;
};

double Line::distance(const Point & lhs, const Point & rhs)
{
    return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) +
                (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy)); 
}

void Line::setPoint(Point & pt, int ix, int iy)
{
    pt._ix = ix;
    pt._iy = iy;
}

int main()
{
    Line line;
    Point p1(1, 2);
    Point p2(11, 12);
    cout << line.distance(p1, p2) << endl;
    line.setPoint(p1, 23, 32);
    p1.print();

    return 0;
}

