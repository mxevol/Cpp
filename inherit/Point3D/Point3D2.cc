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
: public Point
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

class Point4D
: protected Point3D
{
public:
    Point4D(int ix, int iy, int iz)
    : Point3D(ix, iy, iz)
    {
        cout << "Point4D()" << endl;
    }
    void show() const
    {
        print();
        cout << _ix;
    }
};
int main()
{
    Point4D pt4(7, 8, 9);
    //pt4.print();      protected继承，无法通过对象访问成员函数
    //pt4.display();    只有public继承才能通过对象访问public函数
    pt4.show();

    return 0;
}

