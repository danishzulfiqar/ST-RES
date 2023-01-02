#include <bits/stdc++.h>
#include "msoftcon.h"
#include <cstdlib>
#include <ctime>
using namespace std;

const int CPF = 5;
const int maxHorses = 7;
class track;

class horse
{
private:
    const track *ptrTrack;
    const int horse_number;

    float finish_time;
    float distance_run;

public:
    horse(const int n, const track *ptrT) : horse_number(n), ptrTrack(ptrT), distance_run(0.0)
    {
    }

    const horse(string s, const double b, const double d) {}

    ~horse()
    {
    }
    void display_horse(const float elapsed_time);

    void horse_tick() {}
};

class track
{
private:
    horse *hArray[maxHorses];
    int total_horses;
    int horse_count;
    const float track_length;
    float elapsed_time;

public:
    track(float lenT, int nH);
    ~track();
    void display_track();
    void run();
    float get_track_len() const;
};

void horse::display_horse(float elapsed_time)
{
    set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);

    set_color(static_cast<color>(cBLUE + horse_number));

    char horse_char = '0' + static_cast<char>(horse_number);
    putch(' ');
    putch('\xDB');
    putch(horse_char);
    putch('\xDB');

    if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF)
    {
        if (rand() % 3)
        {
            distance_run += 0.2F;
        }
        finish_time = elapsed_time;
    }

    else
    {
        int mins = int(finish_time) / 60;
        int secs = int(finish_time) - mins * 60;
        cout << " Time =" << mins << ":" << secs;
    }
}

track::track(float lenT, int nH) : track_length(lenT), total_horses(nH), horse_count(0), elapsed_time(0.0)
{
    init_graphics();
    total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
    for (int j = 0; j < total_horses; j++)
    {
        hArray[j] = new horse(horse_count++, this);
    }
    time_t aTime;
    srand(static_cast<unsigned>(time(&aTime)));
    display_track();
}

track::~track()
{
    for (int j = 0; j < total_horses; j++)
    {
        delete hArray[j];
    }
}

void track::display_track()
{
    clear_screen();

    for (int f = 0; f <= track_length; f++)
        for (int r = 1; r <= total_horses * 2 + 1; r++)
        {
            set_cursor_pos(f * CPF + 5, r);
            if (f == 0 || f == track_length)
                cout << "\xDE";
            else
                cout << "\xB3";
        }
}

void track::run()

{
    while (!kbhit())
    {
        elapsed_time += 1.75;

        for (int j = 0; j < total_horses; j++)
        {
            hArray[j]->display_horse(elapsed_time);
        }
        wait(500);
    }
    getch();
    cout << endl;
}

float track::get_track_len() const
{
    return track_length;
}

class ComHorse : public horse
{
public:
    ComHorse(string name, double track_length, double max_speed) : horse(name, track_length, max_speed) {}

    void horse_tick(vector<horse *> hArray, int tick_num)
    {
        horse::horse_tick(tick_num);

        bool ahead = distance == max_distance(hArray);

        bool close_behind = false;
        for (horse *h : hArray)
        {
            if (h->distance > distance && h->distance - distance <= 0.1)
            {
                close_behind = true;
                break;
            }
        }

        if (ahead && close_behind)
        {
            speed += 0.1;
        }
    }

private:
    double max_distance(vector<horse *> hArray)
    {
        double max_distance = 0;
        for (horse *h : hArray)
        {
            max_distance = max(max_distance, h->distance);
        }
        return max_distance;
    }
};

class ComTrack : public Track
{
public:
    ComTrack(double track_length, double max_speed) : Track(track_length, max_speed) {}

    void create_horses(int num_horses)
    {
        for (int i = 0; i < num_horses; i++)
        {
            horse.push_back(new ComHorse(f "Horse {i+1}", length, max_speed));
        }
    }
};

int main()
{
    float length;
    int total;

    cout << "\nEnter track length(furlongs; 1 to 12) : ";
    cin >> length;
    cout << "\nEnter number of horses(1 to 7) : ";
    cin >> total;
    track theTrack(length, total);
    theTrack.run();
    ComTrack comtrack(1.0, 1.0);
    comtrack.create_horses(5);
    comtrack.simulate_race(100);
    return 0;
}
