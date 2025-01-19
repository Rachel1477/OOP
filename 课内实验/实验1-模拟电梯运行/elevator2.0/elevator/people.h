#pragma once
#include<iostream>
#include<string>
using namespace std;
class people
{
private:
	int start_floor;
	float weight;
	int target_floor;
	string name;
	int up_down=0; 
public:
	people(int total_floor);
	int read_target();
	string read_rame();
	int read_up_down();
	int read_in_out();
	int read_start_floor();
	float read_weight();
	void write_in_out(int in_out);
};