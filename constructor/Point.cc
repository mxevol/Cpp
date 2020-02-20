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

    void print()
    {
        cout << "(" << _ix << ","
            << _iy << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};
void test0()
{
    Point p1(1,2);
    p1.print();
    Point p2 = p1;
    p2.print();
}
void test1(Point p)
{
    p.print();
}
Point test2()
{
    Point pt(21, 22);
    return pt;

}
void test3()
{
    Point pt(1, 2);
    Point pt1(2, 3);
    pt1 = pt;
    pt1.print();
}
int main()
{
    test3();
    return 0;
}

