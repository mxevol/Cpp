#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }

    void print() const
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" ;
    }

    int getY() const {  return _iy; }

protected:
    int _ix;

private:
    int _iy;
};

class Point3D
: private Point
{
public:
    Point3D(int ix, int iy, int iz)
    : Point(ix, iy)
    , _iz(iz)
    {
        cout << "Point3D(int, int, int)" << endl;
    }

    void display() const
    {
        cout << "(" << _ix
             << "," << getY()
             << "," << _iz
             << ")" ;
    }

private:
    int _iz;
};
int main()
{
    Point pt(1, 2);
    pt.print();
    cout << endl;
    cout << "--------------" << endl;
    Point3D pt3(4, 5, 6);
    pt3.display();
    cout << endl;
    return 0;
}

