#include <iostream>
#include <math.h>
using namespace std;

class ComplexNumber
{
private:
    float real, imaginary;

public:
    ComplexNumber()
    {
        real = imaginary = 0;
    }
    ComplexNumber(float real, float imag)
    {
        this->real = real;
        imaginary = imag;
    }
    void operator++()
    {
        ++real;
        ++imaginary;
    }
    void operator++(int)
    {
        real++;
        imaginary++;
    }
    void operator--()
    {
        --real;
        --imaginary;
    }
    void operator--(int)
    {
        real--;
        imaginary--;
    }
    ComplexNumber operator+(ComplexNumber number)
    {
        ComplexNumber addition;
        addition.real = real + number.real;
        addition.imaginary = imaginary + number.imaginary;
        return addition;
    }
    ComplexNumber operator-(ComplexNumber number)
    {
        ComplexNumber subtraction;
        subtraction.real = real - number.real;
        subtraction.imaginary = imaginary - number.imaginary;
        return subtraction;
    }
    ComplexNumber operator*(ComplexNumber number)
    {
        ComplexNumber multiplication;
        multiplication.real = (real * number.real) - (imaginary * number.imaginary);
        multiplication.imaginary = (imaginary * number.real) + (real * number.imaginary);
        return multiplication;
    }
    ComplexNumber operator/(ComplexNumber number)
    {
        ComplexNumber division;
        float denominator = pow(number.real, 2) + pow(number.imaginary, 2);
        division.real = ((real * number.real) + (imaginary * number.imaginary)) /
                        denominator;
        division.imaginary = ((imaginary * number.real) - (real * number.imaginary)) / denominator;
        return division;
    }
    void operator>>(int shift)
    {
        real = ((int)real) >> shift;
        imaginary = ((int)imaginary) >> shift;
    }
    void operator<<(int shift)
    {
        real = ((int)real) << shift;
        imaginary = ((int)imaginary) << shift;
    }
    void print()
    {
        cout << real << "+" << imaginary << "i";
    }
};

int main()
{
    ComplexNumber postfixInc(4, 5);
    ComplexNumber prefixInc(4, 5);
    ComplexNumber postfixDec(2, 3);
    ComplexNumber prefixDec(2, 3);
    ComplexNumber c1(3, 6);
    ComplexNumber c2(4, 4);
    ComplexNumber add = c1 + c2;
    ComplexNumber sub = c1 - c2;
    ComplexNumber mul = c1 * c2;
    ComplexNumber div = c1 / c2;
    cout << "(";
    postfixInc.print();
    cout << ")++";
    cout << " = ";
    postfixInc++;
    postfixInc.print();
    cout << endl;
    cout << "++(";
    prefixInc.print();
    cout << ")";
    cout << " = ";
    ++prefixInc;
    prefixInc.print();
    cout << endl;
    cout << "(";
    postfixDec.print();
    cout << ")--";
    cout << " = ";
    postfixDec--;
    postfixDec.print();
    cout << endl;
    cout << "--(";
    prefixDec.print();
    cout << ")";
    cout << " = ";
    --prefixDec;
    prefixDec.print();
    cout << endl
         << endl;
    cout << "(";
    c1.print();
    cout << ") + (";
    c2.print();
    cout << ") =";
    add.print();
    cout << endl;
    cout << "(";
    c1.print();
    cout << ") - (";
    c2.print();
    cout << ") =";
    sub.print();
    cout << endl;
    cout << "(";
    c1.print();
    cout << ") * (";
    c2.print();
    cout << ") =";
    mul.print();
    cout << endl;
    cout << "(";
    c1.print();
    cout << ") / (";
    c2.print();
    cout << ") =";
    div.print();
    cout << endl;
    cout << "(";
    c1.print();
    cout << ") >> 1";
    cout << " = ";
    c1 >> 1;
    c1.print();
    cout << endl;
    cout << "(";
    c2.print();
    cout << ") << 1";
    cout << " = ";
    c2 << 1;
    c2.print();
    cout << endl;
    return 0;
}
