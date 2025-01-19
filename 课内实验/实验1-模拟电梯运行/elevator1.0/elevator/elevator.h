#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <iomanip>
#include<windows.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Cdate
{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:

    Cdate() {};
    void run();
    void desplay();
    void is_timeset();
};
class elevator {
private:
    int total_floor;
    int current_floor;
    vector<int> target_floor;
    int up_down = 0;
    Cdate time;
public:
    elevator();
    void start();
    void run_elevator(Cdate&time);
    void set();
};




