class Angle
{
private:
    int degrees;
    float minutes;
    char direction;

public:
    void getdata();
    void display_lat();
    void display_long();
};

class Ship
{
private:
    Angle latitude;
    Angle longitude;
    static int counter;
    int srl_num;

public:
    Ship();
    void get_location();
    void display_location();
};

int Ship::counter = 0;
