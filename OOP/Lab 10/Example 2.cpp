#include <iostream>
#include <stdlib.h>
using namespace std;
class Polygon
{
private:
    double width, height;

public:
    Polygon(double w, double h) : width(w), height(h)
    {
    }
    double getWidth()
    {
        return width;
    }
    double getHeight()
    {
        return height;
    }
    virtual double getArea() = 0; // pure virtual function
    virtual string getType() = 0; // pure virtual function
};
class Rectangle : public Polygon
{
public:
    Rectangle(double w, double h) : Polygon(w, h)
    {
    }
    double getArea()
    {
        return (getWidth() * getHeight());
    }
    string getType()
    {
        return "Rectangle";
    }
};
class Square : public Rectangle
{
public:
    Square(double l) : Rectangle(l, l)
    {
    }
    string getType()
    {
        return "Square";
    }
};
class Parallelogram : public Rectangle
{
public:
    Parallelogram(double w, double h) : Rectangle(w, h)
    {
    }
    string getType()
    {
        return "Parallelogram";
    }
};
class Triangle : public Polygon
{
public:
    Triangle(double w = 0, double h = 0) : Polygon(w, h)
    {
    }
    double getArea()
    {
        return (getWidth() * getHeight()) / 2;
    }
    string getType()
    {
        return "Triangle";
    }
};
int main()
{
    Polygon *ppoly[100] = {new Rectangle(1.2, 2.1),
                           new Square(2.5),
                           new Triangle(6, 4),
                           new Parallelogram(20, 30),
                           new Rectangle(100, 200),
                           new Rectangle(1.2, 2.1),
                           new Square(2.5),
                           new Triangle(6, 4),
                           new Parallelogram(20, 30),
                           new Rectangle(100, 200),
                           NULL}; // array of pointers
    for (int i = 0; ppoly[i] != NULL; i++)
        cout << i + 1 << ". "
             << ppoly[i]->getType() << endl
             << "\n\t- Width = " << ppoly[i]->getWidth()
             << "\n\t- Height = " << ppoly[i]->getHeight()
             << "\n\t- Area = " << ppoly[i]->getArea()
             << endl
             << endl
             << "---------------" << endl
             << endl;
    system("pause");
    return 0;
}