#include "sortlisttemplate.h"

int main()
{
	int* sortarray;
	int i, size;

	// Ask user how many numbers are to be sorted

	cout << "How many numbers?  ";
	cin >> size;

	// Create an array of the right size

	sortarray = new int[size];

	// Create sortlist object of the right type and size

	sortlist<int> testlist(size);

	// Prompt user to enter numbers to be sorted, and store them in sortarray

	cout << "Enter " << size << " integers" << endl;
	for (i = 0; i < size; i++)
		cin >> sortarray[i];

	// Transfer numbers into the Element array of sortlist

	testlist.SetArray(sortarray);


	cout << endl << "Sorted list:" << endl;

	// Sort array using appropriate sorting method, originally selection sort
	// but this will need to be changed for insertion sort.
	testlist.SelectionSort();

	// Transfer numbers back to sortarray, and print them out.

	testlist.GetArray(sortarray);
	for (i = 0; i < size; i++)
		cout << sortarray[i] << ' ';
	cout << endl;
	return 0;
}
