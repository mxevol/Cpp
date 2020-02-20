#include <iostream>
using std::cout;
using std::endl;

class Singeton
{
public:
    static Singeton * getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singeton();
        }
        return _pInstance;
    }

    static void destory()
    {
        if(_pInstance)
            delete _pInstance;
    }

private:
    Singeton();
    ~Singeton();
private:
    static Singeton* _pInstance;
};

Singeton* Singeton::_pInstance = nullptr;
int main()
{
    return 0;
}

