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
    virtual double getArea() // virtual function
    {
        return 0;
    }
    virtual string getType() // virtual function
    {
        return "Generic Polygon";
    }
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
int main()
{
    Polygon *p = new Polygon(20, 30);
    Polygon *r = new Rectangle(20, 30);
    cout << p->getType() << ", Area: " << p->getArea() << endl;
    cout << r->getType() << ", Area: " << r->getArea() << endl;
    return 0;
}