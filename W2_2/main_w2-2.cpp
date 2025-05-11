#include "intlist.h"

int main()
{
	Intlist int_list;
	int object;

	cout << "Enter list of integers, 0 to finish: " << endl << endl;
	cin >> object;
	while (object > 0)
	{
		int_list.Insert(object);
		cin >> object;
	}

	cout << endl << "List: " << int_list << endl << endl;

	cout << "First element: " << int_list.First() << endl << endl;

	int_list.Doublelist();

	cout << endl << "List: " << int_list << endl << endl;

	cout << "Number of elements: " << int_list.Count_elements() << endl << endl;

	cout << "Enter item to find position: ";
	cin >> object;

	int pos = int_list.Position(object);
	if (pos == 0)
		cout << "Item " << object << " is not in the list.";
	else
		cout << "Item " << object << " is at position " << pos << ".";
	cout << endl << endl;

	cout << "Enter item to count occurrences: ";
	cin >> object;

	cout << "Item " << object << " occurs " << int_list.Occurs(object) << " times in the list." << endl << endl;

	cout << "Enter item to add to end of list: ";
	cin >> object;

	int_list.Insert_at_end(object);

	cout << endl << "List: " << int_list << endl << endl;

	return 0;
}

