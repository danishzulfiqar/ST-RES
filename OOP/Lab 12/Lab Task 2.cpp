#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imaginary;

public:
    Complex(float realpart = 0, float imaginarypart = 0);
    Complex Add(const Complex &c) const;
    float GetReal() const;
    float GetImaginary() const;
    void SetReal(float r);
    void SetImaginary(float i);
};
Complex::Complex(float realpart, float imaginarypart)
{
    SetReal(realpart);
    SetImaginary(imaginarypart);
}
void Complex::SetReal(float r)
{
    real = r;
}
void Complex::SetImaginary(float i)
{
    imaginary = i;
}
float Complex::GetReal() const
{
    return real;
}
float Complex::GetImaginary() const
{
    return imaginary;
}
Complex Complex::Add(const Complex &c) const
{
    return Complex(GetReal() + c.GetReal(), GetImaginary() + c.GetImaginary());
}
Complex operator+(const Complex &c1, const Complex &c2)
{
    return c1.Add(c2);
}
int main()
{
    Complex x(-1, 6);
    Complex y(55, 8);
    Complex z = x + y;
    cout << z.GetReal() << '+' << z.GetImaginary() << 'i' << endl;
    return 0;
}