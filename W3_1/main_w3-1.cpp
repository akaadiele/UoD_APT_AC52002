#include "intlist.h"

int main()
{
	Intlist int_list, int_list2;
	int object;

	cout << "Enter list of integers, 0 to finish: " << endl << endl;
	cin >> object;
	while (object > 0)
	{
		int_list.Insert(object);
		cin >> object;
	}

	cout << endl << "List: " << int_list << endl;

	int_list.Delete_last();

	cout << endl << "List: " << int_list << endl;

	int_list.Swap_first_two();

	cout << endl << "List: " << int_list << endl;

	int_list.Swap_elements();

	cout << endl << "List: " << int_list << endl;

	cout << "Enter second list of integers, 0 to finish: " << endl << endl;
	cin >> object;
	while (object > 0)
	{
		int_list2.Insert(object);
		cin >> object;
	}

	cout << endl << "List2: " << int_list2 << endl;

	cout << endl << "List1+List2: " << int_list + int_list2 << endl;
	cout << endl << "List1: " << int_list << endl;
	cout << endl << "List2: " << int_list2 << endl;

	int_list.Append(int_list2);

	cout << endl << "List: " << int_list << endl;

	return 0;
}

