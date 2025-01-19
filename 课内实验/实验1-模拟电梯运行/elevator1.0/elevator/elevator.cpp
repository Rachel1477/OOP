#include"elevator.h"

elevator::elevator()
{
    cout << "welcome to this elevator,Starting initialization now¡£\nPlease enter the total floor and current floor" << endl;
    cout << "total_floor: ";
    cin >> total_floor;
    cout << "current_floor:";
    cin >> current_floor;
    cout << "you can press the 0 on the keyboard to input a new one in anytime" << endl;
};

void elevator::set()
{
    cout << "please set up or doun(1 represent up,2 represent down)" << endl;
    int temp_up_down;
    cin >> temp_up_down;
    while (temp_up_down != 1 && temp_up_down != 2)
    {
        cout << "invalid operation,please input again" << endl;
        cin >> temp_up_down;
    }
    int temp_target_floor;
    cout << "please set your target floor" << endl;
    cin >> temp_target_floor;
    while (temp_target_floor > total_floor || temp_target_floor < 0)
    {
        cout << "invalid floor, please input again" << endl;
        cin >> temp_target_floor;
    }
	target_floor.push_back(temp_target_floor);
    sort(target_floor.begin(), target_floor.end());
	if(up_down ==0) up_down = temp_up_down;
};
void elevator::run_elevator(Cdate& time) {
	while (!target_floor.empty())
	{
		cout << endl<<"current_floor: " << current_floor << endl;
        if (total_floor == current_floor || current_floor == 0) up_down = -up_down;
        else if (current_floor < target_floor.front() && up_down == -1) up_down = -up_down;
        else if (current_floor > target_floor.back() && up_down == 1) up_down = -up_down;
		current_floor += up_down;
        for (int i = 0; i < 5; i++)
        {
            time.run();
            if(GetAsyncKeyState('0') & 0x8000) set();
        }
        auto it = find(target_floor.begin(), target_floor.end(), current_floor);
        if (it != target_floor.end())
        {
            cout << "--------------------------------------------------------" << endl;
            cout << "         The target floor:  "<< *it<<"  has arrived       " << endl;
            cout << "---------------------------------------------------------" << endl;
            auto it = target_floor.begin();
            while (it != target_floor.end()) {
                if (*it == current_floor) {
                    it = target_floor.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
	}
    up_down = 0;

};
void Cdate::is_timeset()
{
    {
        SYSTEMTIME current_time;
        GetLocalTime(&current_time);
        hour = current_time.wHour; minute = current_time.wMinute; second = current_time.wSecond; year = current_time.wYear; month = current_time.wMonth; day = current_time.wDay;
    }
}

void Cdate::run()

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

};

void Cdate::desplay()
{
    cout << endl;
    if (second < 10 && minute < 10) cout << year<<" / "<<month <<" / " << day <<endl << hour << ":0" << minute << ":0" << second << endl;
    else if (minute < 10) cout << year << " / " << month << " / " << day << endl << hour << ":0" << minute << ":" << second << endl;
    else if (second < 10) cout << year << " / " << month << " / " << day << endl << hour << ":" << minute << ":0" << second << endl;
    else cout << year << " / " << month << " / " << day << endl << hour << ":" << minute << ":" << second << endl;

};
void elevator::start()
{
    static Cdate time;
    time.is_timeset();
    while (true)
    {
        set();
        system("CLS");
        run_elevator(time);
    }
}