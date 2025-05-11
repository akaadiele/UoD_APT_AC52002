#include <iostream>
#include <iomanip>
#include <string>
#include "month.h"
using namespace std;

int main() {
	Month Year[12] = { Month("January",31),Month("February",28), Month("March",31), Month("April",30), Month("May",31), Month("June",30),
		Month("July",31), Month("August",31), Month("September",30), Month("October",31), Month("November",30), Month("December",31) };

	int total_days = 0;
	cout << setw(14) << left << "Month" << "Number of days to the end of month" << endl;
	cout << string(48, '-') << endl;

	for (int i = 0; i < 12; i++) {
		total_days += Year[i].Get_days();
		cout << setw(14) << left << Year[i].Get_name() << total_days << endl;
	}
	cout << endl;

	int day_of_year;

	cout << "Enter day of year (in range 1 to 365): ";
	cin >> day_of_year;
	while ((day_of_year < 1) || (day_of_year > 365)) {
		cout << "Invalid day. Day must be in range 1 to 365." << endl;
		cout << "Enter day of year (in range 1 to 365): ";
		cin >> day_of_year;
	}

	int current_month = 0;
	int days_left = day_of_year; // The number of days after the start of current month

	while (days_left > Year[current_month].Get_days()) {
		// Move to the next month
		days_left -= Year[current_month].Get_days();
		current_month++;
	}

	// Now the number of days left is at most the number of days in the current month, so we have the correct month
	cout << endl << "Day " << day_of_year << " is " << days_left << " " << Year[current_month].Get_name() << "." << endl << endl;

	return 0;
}

