#pragma once
#ifndef MONTH_H 
#define MONTH_H

#include <string>
using namespace std;

class Month
{
private:
	string Name;
	int Number_of_days;
public:
	Month();
	Month(string month_name, int month_days);
	void Set_name(string month_name);
	void Set_days(int month_days);
	string Get_name();
	int Get_days();
};
#endif
