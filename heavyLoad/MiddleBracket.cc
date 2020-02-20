#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Buffer
{
public:
    Buffer(size_t sz)
    : _sz(sz)
    , _data(new char[_sz]())
    {
        cout << "Buffer(size_t)" << endl;
    }

    size_t size() const
    {
        return strlen(_data);
    }

    size_t capacity() const
    {
        return _sz;
    }

    char & operator[](size_t idx)
    {
        if(idx < capacity()){
            return _data[idx];
        }else{
            static char nullchar = '\0';
            cout << ">> error 下标越界" << endl;
            return nullchar;
        }
    }

    ~Buffer()
    {
        if(_data)
            delete [] _data;
    }

private:
    size_t _sz;
    char * _data;
};
int main()
{
    std::string pstr = "hello,world";
    cout << "pstr = " << pstr << endl;
    Buffer buf(20);
    size_t sz = pstr.size();
    for(size_t idx = 0; idx != sz; ++idx){
        buf[idx] = pstr[idx];
    }

    cout << "buf = " << endl;
    for(size_t idx = 0; idx != buf.size(); ++idx){
        cout << buf[idx] << " ";
    }
    cout << endl;

    return 0;
}

