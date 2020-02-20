#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CowString
{
    class CharProxy
    {
    public:
        CharProxy(int idx, CowString & self)
        : _idx(idx)
        , _self(self)
        {}

        char & operator=(const char & ch);
        friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
    private:
        int _idx;
        CowString & _self;

    };
    friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
public:
    CowString();
    CowString(const char *pstr);
    CowString(const CowString & rhs);
    CowString & operator=(const CowString & rhs);
    ~CowString();

    int RefCount()
    {
        return (*(int*)(_pstr - 4));
    }
    CharProxy operator[](int idx);

    const char* c_str() const { return _pstr;   }
    int size() const {  return strlen(_pstr);   }

private:
    void initRefCount() {    *(int*)(_pstr - 4) = 1; }
    void increaseRefCount() {   ++*(int*)(_pstr - 4);   }
    void decreaseRefCount() {   --*(int*)(_pstr - 4);   }
    void release()
    {
        decreaseRefCount();
        if(RefCount() == 0){
            delete [] (_pstr - 4);
            cout << ">>> delete data!" << endl;
        }

    }
    friend std::ostream & operator<<(std::ostream & os, const CowString & rhs);
private:
    char * _pstr;
};


CowString::CowString()
: _pstr(new char[1 + 4]() + 4)
{
    cout << "CowSring()" << endl;
    initRefCount();
}

CowString::CowString(const char* pstr)
: _pstr(new char[strlen(pstr) + 5]() + 4)
{
    initRefCount();
    strcpy(_pstr, pstr);
    cout << "CowString(const char *)" << endl;
}

CowString::CowString(const CowString & rhs)
{
    cout << "CowString(const CowString & rhs)" << endl;
    _pstr = rhs._pstr;
    increaseRefCount();
}

CowString & CowString::operator=(const CowString & rhs)
{
    cout << "CowString & operator=(const CowString & rhs)" << endl;
    if(this != & rhs){
        release();
        _pstr = rhs._pstr;
        increaseRefCount();
    }
    return *this;
}

CowString::~CowString()
{
    release();
}

std::ostream & operator<<(std::ostream & os, const CowString & rhs)
{
    os << rhs._pstr;
    return os;
}
CowString::CharProxy CowString::operator[](int idx)
{
    return CharProxy(idx, *this);
}
char &  CowString::CharProxy::operator=(const char & ch)
{
    int sz = _self.size();
    if(_idx >= 0 && _idx < sz){
        if(_self.RefCount() > 1){
            _self.decreaseRefCount();
            char * ptmp = new char[sz + 5]() + 4;
            strcpy(ptmp, _self._pstr);
            _self._pstr = ptmp;
            _self.initRefCount();
        }
        _self._pstr[_idx] = ch;
        return _self._pstr[_idx];
    }else{
        cout << "下标越界！" << endl;
        static char nullchar = '\0';
        return nullchar;
    }
    
}
std::ostream & operator<<(std::ostream & os, const CowString::CharProxy & rhs)
{
    os << rhs._self._pstr[rhs._idx];
    return os;
}

int main()
{
    CowString s0;
    cout << "s0 = " << s0 << endl;

    CowString s1("hello,world");
    CowString s2(s1);

    CowString s3 = "shenzhen";
    s3 = s1;

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address %p\n",s1.c_str());
    printf("s2's address %p\n",s2.c_str());
    printf("s3's address %p\n",s3.c_str());
    cout << "s1's refCount = " << s1.RefCount() << endl;
    cout << "s2's refCount = " << s2.RefCount() << endl;
    cout << "s3's refCount = " << s3.RefCount() << endl;
    
    cout << endl << "执行 cout << s1[0] 之后：" << endl;
    cout << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address %p\n",s1.c_str());
    printf("s2's address %p\n",s2.c_str());
    printf("s3's address %p\n",s3.c_str());
    cout << "s1's refCount = " << s1.RefCount() << endl;
    cout << "s2's refCount = " << s2.RefCount() << endl;
    cout << "s3's refCount = " << s3.RefCount() << endl;

    cout << endl << "执行 s1[0] = 'H' 之后：" << endl;
    s1[0] = 'H';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address %p\n",s1.c_str());
    printf("s2's address %p\n",s2.c_str());
    printf("s3's address %p\n",s3.c_str());
    cout << "s1's refCount = " << s1.RefCount() << endl;
    cout << "s2's refCount = " << s2.RefCount() << endl;
    cout << "s3's refCount = " << s3.RefCount() << endl;

    return 0;
}

