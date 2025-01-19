#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <iomanip>
#include<windows.h>
#include"people.h"
#include<queue>
using namespace std;

class Cdate
{
private:
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
    float max_weight;
    float current_weight;
    int total_floor;
    int current_floor;
    vector<people> people_date;
    vector<people>post;
    int e_up_down = 0;
    Cdate time;
public:
    elevator();
    void people_in();
    void people_out();
    int check(people &A);
    void send_post();
    void start();
    void run_elevator(Cdate& time);
    void operate();

};




