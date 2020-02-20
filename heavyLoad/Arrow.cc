#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
    Data(int ix = 0)
    : _ix(ix)
    {   cout << "Data(int)" << endl;    }
    
    int ix() const {    return _ix; }

    ~Data()
    {
        cout << "~Data()" << endl;
    }
private:
    int _ix;
};

class MiddleLayer
{
public:
    MiddleLayer(Data * pData)
    : _pData(pData)
    {   cout << "MiddleLayer(Data * pData)" << endl;    }

    Data * operator->()
    {
        return _pData;
    }

    Data & operator*()
    {
        return *_pData;
    }

    ~MiddleLayer()
    {
        cout << "~MiddleLayer()" << endl;
        if(_pData)
            delete _pData;
    }

private:
    Data* _pData;
};

class ThridLayer
{
public:
    ThridLayer(MiddleLayer * ml)
    : _ml(ml)
    {   cout << "ThridLayer(MiddleLayer * ml)" << endl; }
    
    MiddleLayer * operator->()
    {
        return _ml;
    }

    ~ThridLayer()
    {
        cout << "~ThridLayer()" << endl;
        if(_ml)
            delete _ml;
    }

private:
    MiddleLayer * _ml;
};
int main()
{
    //MiddleLayer ml(new Data(10));
    //cout << ml->ix() << endl;
    //cout << (*ml).ix() << endl;

    ThridLayer tl(new MiddleLayer(new Data(20)));
    cout << tl.operator->()->operator->()->ix() << endl;

    return 0;
}

