#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
    Complex(double real, double image)
    : _real(real)
    , _image(image)
    {   cout << "Complex(int real, int image)" << endl; }

    void print() const
    {
        cout << _real << "+" << _image << "i" << endl;
    }

    double getReal() const { return _real;   }
    double getImage() const {    return _image;  }

private:
    double _real;
    double _image;
};

Complex operator+(const Complex & lhs, const Complex & rhs)
{
    cout << "Complex operator+" << endl;
    return Complex(lhs.getReal() + rhs.getReal(),lhs.getImage() + rhs.getImage());
}
int main()
{
    Complex c1(11.11, 22.22);
    Complex c2(33.33, 44.44);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}

