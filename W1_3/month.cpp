#include "month.h"

Month::Month() : Name(""), Number_of_days(0)
{
}

Month::Month(string month_name, int month_days) : Name(month_name), Number_of_days(month_days)
{
}

void Month::Set_name(string month_name) {
	Name = month_name;
}

void Month::Set_days(int month_days) {
	Number_of_days = month_days;
}

string Month::Get_name() {
	return Name;
}

int Month::Get_days() {
	return Number_of_days;
}
