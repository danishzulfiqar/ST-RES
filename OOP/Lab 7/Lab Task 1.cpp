#include <iostream>
#include <string>
using namespace std;

class publication
{

protected:
    string title;
    float price;

public:
    publication()
    {
        title = " ";

        price = 0.0;
    }

    publication(string t, float p)
    {
        title = t;
        price = p;
    }

public:
    void getdata()

    {

        cout << "Enter title of publication: ";

        cin >> title;

        cout << "Enter price of publication: ";

        cin >> price;
    }

    void putdata(void)

    {
        cout << "Publication titles :" << title << endl;
        cout << "Publication price :" << price << endl;
    }
};

class book : public publication
{

    int pagecount;

public:
    book()

    {

        pagecount = 0;
    }

    book(string t, float p, int pc) : publication(t, p)

    {

        pagecount = pc;
    }

    void getdata(void)

    {

        publication::getdata();

        cout << "Enter Book Page Count :";

        cin >> pagecount;
    }

    void putdata(void)

    {

        publication::putdata();

        cout << "Book page count:" << pagecount << endl;
    }
};

class CD : public publication
{
    float time1;

public:
    CD()
    {

        time1 = 0.0;
    }

    CD(string t, float p, float tim) : publication(t, p)

    {

        time1 = tim;
    }

    void getdata(void)
    {
        publication::getdata();
        cout << "Enter tape's playing time:";
        cin >> time1;
    }

    void putdata(void)
    {
        publication::putdata();
        cout << " Tape's playing time :" << time1 << endl;
    }
};

int main()
{
    cout << endl;
    cout << "Book data" << endl;

    book b("C++", 230, 300);

    b.putdata();

    cout << endl;
    cout << "CD Data" << endl;

    CD c("C++", 100, 120.5);

    c.putdata();

    cout << "\n Enter New Details Of Book :\n";

    b.getdata();

    c.getdata();

    cout << "\n\n Book data entered by user:\n";

    b.putdata();

    c.putdata();

    return 0;
}