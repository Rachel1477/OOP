#pragma once
#include"people.h"
people::people(int total_floor)
{
	cout << "input your name" << endl;
	cin >> name;
	cout << "set your start floor" << endl;
	cin >> start_floor;
	while (start_floor > total_floor || start_floor <= 0)
	{
		cout << "illegal value,please input again" << endl;
		cin >> start_floor;
	}
	cout << "input your target_floor" << endl;
	cin >> target_floor;
	while (target_floor > total_floor || target_floor <= 0 || target_floor == start_floor)
	{
		cout << "illegal value,please input again" << endl;
		cout << "input your target_floor" << endl;
		cin >> target_floor;
	}
	if (target_floor > start_floor) up_down = 1;
	else up_down = -1;
	cout << "input this people's weight" << endl;
	cin >> weight;
}
string people::read_rame()
{
	return name;
}
int people::read_target()
{
	return target_floor;
}
int people::read_up_down()
{
	return up_down;
}
int people::read_start_floor()
{
	return start_floor;
}
float people::read_weight()
{
	return weight;
}
