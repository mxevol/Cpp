#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String()
    : _pstr(new char[1]())
    {   cout << "String()" << endl; }

    String(const char * pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(const String & rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    String & operator=(const String & rhs)
    {
        cout << " String & operator=(const String & rhs)" << endl;
        if(this != &rhs){
            delete [] _pstr;
            new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    void print() const
    {
        cout << _pstr << endl;
    }

    ~String()
    {
        cout << "~String()" << endl;
        delete [] _pstr;
    }

private:
    char * _pstr;
};
int main()
{
    String s1("helloworld");
    s1.print();

    String s2 = s1;
    s2.print();

    String s3("asdads");
    s3 = s2;
    s3.print();
    return 0;
}

