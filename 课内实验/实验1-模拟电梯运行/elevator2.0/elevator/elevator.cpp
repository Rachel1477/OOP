#include <algorithm>
#include"elevator.h"
#include"people.h"
int f(int current_floor, int start_floor)
{
    if (current_floor > start_floor) return -1;
    return 1;
}
elevator::elevator()
{
    cout << "welcome to this elevator,Starting initialization now¡£\nPlease enter the total floor and current floor" << endl;
    cout << "total_floor: ";
    cin >> total_floor;
    cout << "current_floor:";
    cin >> current_floor;
    cout << "the total weight" << endl;
    cin >> max_weight;
    cout << "you can press 0 to insert your operate" << endl;
};
void elevator::people_in()
{
    post.erase(remove_if(post.begin(), post.end(), [this]( people& p) {
        if (check(p) == 2) {
            people_date.push_back(p);
            current_weight += p.read_weight();
            cout << "-----------------------------------------------------------" << endl;
            cout << "people: " << p.read_rame() << "  get in the elevator" << endl;
            cout << "weight condition:  " << current_weight << "/" << max_weight << endl;
            cout << "------------------------------------------------------------" << endl;
            return true;
        }
        else if (check(p) == 1) {
            cout << "people :" << p.read_rame() << "  is overweight,fail to go in the elevator (the post will be saved until the elevator get this floor again)" << endl;
            cout << "weight condition:  " << current_weight << "/" << max_weight << endl;
            return false;
        }
        return false;
        }), post.end());
}
void elevator::send_post()
{
    cout << endl;
    cout << "input how many people will in the elevator,      current floor--->  " << current_floor << endl;
    int num;
    cin >> num;
    while (num--)
    {
        cout << endl << "----here to initialize one person's information----" << endl;
        people temp(total_floor);    
        post.push_back(temp);
    }
}
void elevator::people_out() {

    if (people_date.size() != 0)
    {
        oo:
        int temp = 0;
            for(auto it = people_date.begin(); it != people_date.end(); ++it)
            {
                if (current_floor == (*it).read_target())
                {
                    current_weight -= (*it).read_weight();
                    cout <<endl<< "------------------------------------------------" <<endl; 
                    cout << "floor :" << current_floor << "arrived" << endl << ",people " << (*it).read_rame() << " go  out  the elevator" << endl; 
                    cout << "weight condition:  " << current_weight << "/" << max_weight << endl;
                    cout << "------------------------------------------------" << endl<<endl;
                    people_date.erase(people_date.begin() + temp);
                    goto oo;

                }
                temp++;
        }
    }
}
int elevator::check(people &A)
{
    if (A.read_start_floor() == current_floor)
    {
        if (A.read_weight() + current_weight <= max_weight)
        {
            return 2;
        }
        else return 1;
    }
    else return 0;
}


void Cdate::is_timeset()
{
    {
        SYSTEMTIME current_time;
        GetLocalTime(&current_time);
        hour = current_time.wHour; minute = current_time.wMinute; second = current_time.wSecond;
    }
}
void Cdate::run()
{
    {
        Sleep(1000);
        if (second > 59)
        {
            minute += 1;
            second = 0;
        }
        if (minute > 59)
        {
            hour += 1;
            minute = 0;
        }
        if (hour >= 24)
        {
            hour = 0;
        }
        desplay();
        second++;
    }
};
void Cdate::desplay()
{
    if (second < 10 && minute < 10) cout << hour << ":0" << minute << ":0" << second << endl;
    else if (minute < 10) cout << hour << ":0" << minute << ":" << second << endl;
    else if (second < 10) cout << hour << ":" << minute << ":0" << second << endl;
    else cout << hour << ":" << minute << ":" << second << endl;

};
void elevator::operate()
{
    cout << "please determinate your operate:" << endl << "1 . new one get in the elevator" << endl << "2.  check how many people in the elevator" << endl;
    int i;
    cin >> i;
    while (i != 1 && i != 2)
    {
        cout << "illegal operate ,please input again" << endl;
        cin >> i;
    }
    if (i == 1) send_post();
    else if (i == 2)
    {
        cout <<endl<< "The following are the persons in the elevator" << endl<<endl;
        if (people_date.size() == 0) cout << "the elevator is empty" << endl;
        else
        {
            for (auto it = people_date.begin(); it != people_date.end(); ++it)
            {
                cout << "name: " << (*it).read_rame() << "   " << "   weight: " << (*it).read_weight() << "   target floor : " << (*it).read_target() << endl;
            }
            cout << "weight condition:  " << current_weight << "/" << max_weight << endl;
        }
    }
}
void elevator::run_elevator(Cdate& time) {
    int max1 = -100, min1 = total_floor, max2 = -100, min2 = total_floor;
    if (e_up_down == 0 && (!post.empty())) e_up_down = f(current_floor,post[0].read_start_floor());
    while (e_up_down != 0)
    {
        cout << "current_floor: " << current_floor << endl;
        people_in();
        people_out();
        if (total_floor  == current_floor) e_up_down = -e_up_down;
        if (current_floor == -1) e_up_down = -e_up_down;
        if (people_date.size() != 0)
        {
            for (auto it = people_date.begin(); it != people_date.end(); ++it)
            {
                if ((*it).read_target() < min1) min1 = (*it).read_target();
                if ((*it).read_target() > max1) max1 = (*it).read_target();
            }
        }
        for (auto it = post.begin(); it != post.end(); ++it)
        {
            if ((*it).read_start_floor() < min2) min2 = (*it).read_start_floor();
            if ((*it).read_start_floor() > max2) max2 = (*it).read_start_floor();
        }
        //cout << "max1=" << max1 << " min1=" << min1 << "max2= " << max2 << " min2= " << min2 << endl;

        if (!(max1 == -100 && min1 == total_floor))
        {
            if ((current_floor >= max1 && e_up_down == 1 && max2 <= current_floor) || (current_floor <= min1 && e_up_down == -1 && min2 >= current_floor)) e_up_down = -e_up_down;
        }
        current_floor += e_up_down;
        for (int i = 0; i < 3; i++)
        {
            time.run();
            if (GetAsyncKeyState('0') & 0x8000) operate();
        }
        
        if (people_date.size() == 0 && post.size() == 0)
        {
            e_up_down = 0; cout << "The elevator is empty and will be temporarily suspended on the floor ---->" << current_floor << endl;
        }
    }

};
void elevator::start()
{
    static Cdate time;
    time.is_timeset();
    send_post();
    while (true)
    {
        //system("CLS");
        run_elevator(time);
        if (GetAsyncKeyState('0') & 0x8000) operate();
    }
}
