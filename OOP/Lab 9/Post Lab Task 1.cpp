#include <bits/stdc++.h>
using namespace std;

class Convert_no_to_char
{
private:
    int no;

public:
    Convert_no_to_char() {}
    Convert_no_to_char(int i) : no(i) {}
    void get_no()
    {
        cout << "\nEnter digits to be converted into character:";
        cin >> no;
    }
    void no_to_char()
    {
        int rev = 0, r = 0;
        while (no > 0)
        {
            r = no % 10;
            rev = rev * 10 + r;
            no = no / 10;
        }
        cout << "Digits into word:";
        while (rev > 0)
        {
            r = rev % 10;
            switch (r)
            {
            case 1:
                cout << "one ";
                break;
            case 2:
                cout << "two ";
                break;
            case 3:
                cout << "three ";
                break;
            case 4:
                cout << "four ";
                break;
            case 5:
                cout << "five ";
                break;
            case 6:
                cout << "six ";
                break;
            case 7:
                cout << "seven ";
                break;
            case 8:
                cout << "eight ";
                break;
            case 9:
                cout << "nine ";
                break;
            case 0:
                cout << "zero ";
                break;
            default:
                cout << "UnValid ";
                break;
            }
            rev = rev / 10;
        }
    }

    void display()
    {
        cout << "\n\nDisplay:";
        cout << "\nNumbers:" << no << endl;
    }
};

class convert_char_to_no
{
private:
    int i;
    string a[100];

public:
    void char_to_no()
    {
        char c;
        do
        {
            cout << "\nEnter digits in form of word:";
            cin >> a[i];
            i++;
            cout << "Enter y to continue or otherwise enter n:";
            cin >> c;
        } while (c == 'y');

        for (i = 0; i < 100; i++)
        {
            if (a[i] == "one")
            {
                cout << "1";
            }
            else if (a[i] == "two")
            {
                cout << "2";
            }
            else if (a[i] == "three")
            {
                cout << "3";
            }
            else if (a[i] == "four")
            {
                cout << "4";
            }
            else if (a[i] == "five")
            {
                cout << "5";
            }
            else if (a[i] == "six")
            {
                cout << "6";
            }
            else if (a[i] == "seven")
            {
                cout << "7";
            }
            else if (a[i] == "eight")
            {
                cout << "8";
            }
            else if (a[i] == "nine")
            {
                cout << "9";
            }
            else if (a[i] == "zero")
            {
                cout << "0";
            }
            else
            {
                exit(1);
            }
        }
    }
};
int main()
{
    cout << "Enter a number:" << endl;
    Convert_no_to_char c1, c2(7809);
    c1.get_no();
    c1.display();
    c1.no_to_char();
    c2.display();
    c2.no_to_char();
    cout << "\n\nWords into digits:" << endl;
    convert_char_to_no c3;
    c3.char_to_no();
    return 0;
}
