#include <iostream>
using namespace std;

int main() {

	//	cout << "Hello World";
	//	//std::cout << "Hello World";


	// ------------------------------------------------------------------------

		//cout << "Hello World!" << endl;
		//cout << "I am (enter your name)" << endl;

	// ------------------------------------------------------------------------

		//cout << "******************" << endl;
		//cout << "*                *" << endl;
		//cout << "* HAPPY BIRTHDAY *" << endl;
		//cout << "*                *" << endl;
		//cout << "******************" << endl;

	// ------------------------------------------------------------------------

	//int age;
	//cout << "Please type in your age, then press Enter." << endl;
	//cin >> age;
	//cout << endl;
	//cout << endl;
	//if (age >= 17)
	//{
	//	cout << "You can now learn to drive!" << endl;
	//}
	//else
	//{
	//	cout << "You cannot learn to drive yet, sorry." << endl;
	//}

	// ------------------------------------------------------------------------

	int age, yearsLeft;
	cout << "Please type in your age, then press Enter." << endl;
	cin >> age;
	cout << endl;
	cout << endl;
	if (age >= 17)
	{
		cout << "You can now learn to drive!" << endl;
	}
	else
	{
		cout << "You cannot learn to drive yet, sorry." << endl;

		yearsLeft = 17 - age;
		cout << "You have " << yearsLeft << " years left to wait." << endl;
	}

	// ------------------------------------------------------------------------

	return 0;
}