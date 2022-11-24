#include <iostream>

using namespace std;

class Student
{

public:
    Student() {}
    virtual void getnum()
    {
        cout << "Enter roll no: ";
        cin >> rollno;
    }
    virtual void putnum()
    {
        cout << "Roll no is: " << rollno << "\n";
    }

private:
    int rollno;
};
class Test : virtual public Student
{
public:
    Test() {}

    void getmarks()
    {
        cout << "Enter mark 1: ";
        cin >> mark1;
        cout << "Enter mark 2: ";
        cin >> mark2;
        cout << "Enter mark 3: ";
        cin >> mark3;
    }
    void putmarks()
    {
        cout << "Mark 1: " << mark1 << "\n";
        cout << "Mark 2: " << mark2 << "\n";
        cout << "Mark 3: " << mark3 << "\n";
    }

protected:
    int mark1;
    int mark2;
    int mark3;
};
class Sports : virtual public Student
{
public:
    Sports() {}
    void getscore()
    {
        score = -1;
        while (score < 0 || score > 100)
        {
            cout << "Enter score: ";
            cin >> score;
        }
    }
    void putscore()
    {
        cout << "Score: " << score << "\n";
    }

protected:
    int score;
};

class Result : public Test, public Sports
{
public:
    Result() {}

    void display()
    {
        int total = score + mark1 + mark2 + mark3;
        cout << "The total (marks + score): " << total << "\n";
    }

private:
    int total;
};

int main()
{
    Result result;
    result.getnum();
    result.getmarks();
    result.getscore();
    result.putmarks();
    result.putscore();
    result.display();
    return 0;
}