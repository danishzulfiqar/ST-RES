#include <bits/stdc++.h>
using namespace std;

class Computer
{
protected:
    double w_size;
    double m_size;
    double s_size;
    double speed;

public:
    Computer(double word_size, double memory_size, double storage_size, double sp)
    {
        w_size = word_size;
        m_size = memory_size;
        s_size = storage_size;
        speed = sp;
    }

    void display()
    {
        cout << "Word Size: " << w_size << "\nMemory: " << m_size << "\nStorage: " << s_size << "\nSpeed: " << speed << endl;
    }
};

class Laptops : public Computer
{
    double length;
    double width;
    double height;
    double weight;

public:
    Laptops(double word_size, double memory_size, double storage_size, double sp, double l, double w, double h, double wh) : Computer(word_size, memory_size, storage_size, sp)
    {
        length = l;
        width = w;
        height = h;
        weight = wh;
    }

    void display(void)
    {
        Computer::display();
        cout << "Length: " << length << "\nWidth: " << width << "\nHeight: " << height << "\nWeight: " << weight;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Computer C1(12235, 4355, 535, 52325);
    C1.display();

    Laptops s1(1214, 14141, 1441, 12424, 42, 97.5, 15.6, 18.8);
    s1.display();

    return 0;
}