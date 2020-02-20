#include <iostream>
#include <limits>
using std::cout;
using std::endl;

class Complex
{
public:
    Complex(double real = 0, double image = 0)
    : _real(real)
    , _image(image)
    {   cout << "Complex(int real, int image)" << endl; }

    void print() const
    {
        cout << _real << "+" << _image << "i" << endl;
    }

    Complex & operator++()
    {
        ++_real;
        ++_image;
        return *this;
    }

    Complex operator++(int)
    {
        Complex tmp(*this);
        ++_real;
        ++_image;
        return tmp;
    }

    Complex & operator+=(const Complex & rhs)
    {
        _real += rhs._real;
        _image += rhs._image;
        return *this;
    }
    friend bool operator==(const Complex & lhs, const Complex & rhs);
    friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
    friend std::istream & operator>>(std::istream & is, Complex & rhs);
private:
    double _real;
    double _image;
};

Complex operator+(const Complex & lhs, const Complex & rhs)
{
    Complex tmp(lhs);
    tmp += rhs;
    return tmp;
}

bool operator==(const Complex & lhs, const Complex & rhs)
{
    return (lhs._real == rhs._real && lhs._image == rhs._image);
}

bool operator!=(const Complex & lhs, const Complex & rhs)
{
    return !(lhs == rhs);
}

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
    cout << rhs._real << "+" << rhs._image << "i" ;
    return os;
}

void readDouble(std::istream &is, double & value)
{
    cout << ">>> pls input a valid double number:" << endl;
    while(is >> value, !is.eof()){
        if(is.bad()){
            cout << "istream is corrupted!" << endl;
        }else if(is.fail()){
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << ">>> pls input a valid double number:" << endl;
            continue;
        }
        break;
    }
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
    readDouble(is, rhs._real);
    readDouble(is, rhs._image);
    return is;
}


int test0()
{
    Complex c1(11.11, 22.22);
    cout << "c1 = " << c1 << endl;
    Complex c2(33.33, 44.44);
    cout << "c2 = " << c2 << endl;
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}

void test1()
{
    Complex c1;
    std::cin >> c1;
    c1.print();
}

void test2()
{
    Complex c1(11.11, 22.22);
    cout << ++c1 << endl;
    cout << c1++ << endl;
    cout << c1 << endl;
}

int main(void)
{
    test2();
    return 0;
}

