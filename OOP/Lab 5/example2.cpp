#include <iostream>
using namespace std;
class Distance // English Distance class
{
private:
    int feet;
    float inches;

public:
    Distance()
    {
        cout << "default constructor" << endl;
        feet = 0;
        inches = 0;
    }
    Distance(float mtrs)
    {
        // this constructor convert meters to feet and inches
        cout << "one argument constructor" << endl;
        float ft = mtrs * 3.28084; // convertinf meters to feet
        feet = (int)ft;            // extracting int part from ft
        inches = (ft - feet) * 12; // converting decimal part of ft into inches
    }
    Distance(int f, float i)
    {
        cout << "two argument constructor" << endl;
        feet = f;
        inches = i;
    }
    void setdist(int ft, float in)
    { // set Distance to args
        feet = ft;
        inches = in;
    }
    void getdist()
    { // get length from user
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void initialize()
    {
        feet = 0;
        inches = 0;
    }
    void showdist()
    { // display distance
        cout << "feet = " << feet << "\t inches = " << inches << endl;
    }
};
int main()
{
    /*two objects are created so default constructor is called two times*/
    Distance dist1, dist2; // objects data member are initialize by default
        /* if default constructor is not present then
        we have to call initialize function with each
        object to initialize its private data member */
        // dist1.initialize(); // in comments because we have
        // dist2.initialize(); // default constructor

        dist1.setdist(11, 6.25); // set dist1 values using setdist function
    Distance dist3(3, 5.75);     // here 2 argument constructor will be called
    // that initialize dist3 data member with 3 and 5.75 values
    Distance dist4(1); // here 1 argument construct will be called

    cout << "dist1 : ";
    dist1.showdist();
    cout << "dist2 : ";
    dist2.showdist();
    cout << "dist3 : ";
    dist3.showdist();
    cout << "dist4 : ";
    dist4.showdist();
    
    return 0;
}
