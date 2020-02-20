#include <vector>
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::list;

class Point
{
public:
    Point(double ix, double iy)
    : _dx(ix)
    , _dy(iy)
    {   cout << "Point(double, double)" << endl;}

    template<class T>
    T cast(T t)
    {
        return T(t * _dx);
    }

private:
    double _dx;
    double _dy;
};

void test0()
{
    Point pt(1.11, 2.22);
    cout << "pt.case() = " << pt.cast(10) << endl;
}

class Data
{
public:
    Data(int sz = 10)
    : _sz(sz)
    , _data(new int[_sz]())
    {}

    template<class Iterator>
    Data(Iterator beg, Iterator end)
    : _sz(end - beg)
    , _data(new int[_sz]())
    {}

    template<class Iterator>
    void setData(Iterator beg, Iterator end)
    {
        int idx;
        for(idx = 0; beg != end; ++beg)
        {
            _data[idx++] = *beg;
        }
    }
    ~Data()
    {
        if(_data)
            delete [] _data;
    }

    void print() const
    {
        for(int idx = 0; idx < _sz; idx++){
            cout << _data[idx] << " ";
        }
        cout << endl;
    }

private:
    int _sz;
    int * _data;
};

void test1()
{
    vector<int> numbers{1,2,3,4,5,6,7,8,9};
    Data data(numbers.begin(),numbers.end());
    data.setData(numbers.begin(),numbers.end());
    data.print();
}
int main()
{
    test1();
    return 0;
}

