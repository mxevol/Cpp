#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:

    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int,int)" << endl;
    }

    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(const Point & rhs)" << endl;
    }

    Point & operator=(const Point &rhs)
    {
        _ix = rhs._ix;
        _iy = rhs._iy;
        cout << "Point & operator=(const Point &rhs)" << endl;
        return *this;
    }

    void print() const
    {
        cout << "(" << _ix << ","
            << _iy << ")";
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

class Line
{
public:
    Line(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {
        cout << "Line(int x1, int y1, int x2, int y2)" << endl;
    }

    void print() const
    {
        _pt1.print();
        cout << "----->";
        _pt2.print();
        cout << endl;
    }

private:
    Point _pt1;
    Point _pt2;
};
int main()
{
    Line l(1, 2, 3, 4);
    l.print();
    return 0;
}

