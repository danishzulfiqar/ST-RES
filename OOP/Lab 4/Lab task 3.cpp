#include <iostream>
using namespace std;
class Complex
{
private:
    double real, imag;

public:
    Complex()
    {
        real = 0.0;
        imag = 0.0;
    }

    Complex(double r, double im)
    {
        real = r;
        imag = im;
    }

    void show();

    Complex Add(Complex &b);

    Complex sub(Complex &b);

    Complex mul(Complex &b);
};

void Complex::show()
{
    cout << real << "+" << imag << "i" << endl;
}

Complex Complex ::Add(Complex &b)
{
    cout << "Addition" << endl;
    return Complex(real + b.real, imag + b.imag);
}
Complex Complex ::sub(Complex &b)
{
    cout << "Subtraction" << endl;
    return Complex(real - b.real, imag - b.imag);
}
Complex Complex ::mul(Complex &b)
{
    cout << "Multiplication" << endl;
    return Complex(real * b.real, imag * b.imag);
}

int main()
{
    Complex C1(11, 2.3);
    Complex C2(9, 2.3);
    Complex C3, C4, C5;

    C3 = C1.Add(C2);
    C3.show();

    C4 = C1.sub(C2);
    C4.show();

    C5 = C1.mul(C2);
    C5.show();
    return 0;
}
