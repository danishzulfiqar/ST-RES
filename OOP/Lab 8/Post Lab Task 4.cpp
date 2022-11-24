#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class publication
{
private:
    string title;
    float price;

public:
    void getdata(void)
    {
        string t;
        float p;
        cout << "Enter title of publication: ";
        cin >> t;
        cout << "Enter price of publication: ";
        cin >> p;
        title = t;
        price = p;
    }
    void putdata(void)
    {
        cout << "Publication title: " << title << endl;
        cout << "Publication price: " << price << endl;
    }
};

class sales
{
private:
    float s1, s2, s3;

public:
    void getdata(void)
    {
        cout << "Enter month 1 sale: $";
        cin >> s1;
        cout << "Enter month 2 sale: $";
        cin >> s2;
        cout << "Enter month 3 sale: $";
        cin >> s3;
    }
    void putdata(void)
    {
        cout << "Month 1 sale: $" << s1 << endl;
        cout << "Month 2 sale: $" << s2 << endl;
        cout << "Month 3 sale: $" << s3 << endl;
    }
};

class book : public publication, public sales
{
private:
    int pagecount;

public:
    void getdata(void)
    {
        publication::getdata();
        sales::getdata();
        cout << "Enter Book Page Count: ";
        cin >> pagecount;
    }
    void putdata(void)
    {
        publication::putdata();
        sales::putdata();
        cout << "Book page count: " << pagecount << endl;
    }
};

class tape : public publication, public sales
{
private:
    float ptime;

public:
    void getdata(void)
    {
        publication::getdata();
        sales::getdata();
        cout << "Enter tap's playing time: ";
        cin >> ptime;
    }
    void putdata(void)
    {
        publication::putdata();
        sales::putdata();
        cout << "Tap's playing time: " << ptime << endl;
    }
};

int main()
{
    book b;
    tape t;
    b.getdata();
    t.getdata();

    cout << "\nThe Given Data is:" << endl;
    b.putdata();
    t.putdata();

    return 0;
}