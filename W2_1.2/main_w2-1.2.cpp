#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    Queue int_queue(4);
    char choice;
    int i;

    cout << "a for add, r for remove, q for quit" << endl << endl;
    cin >> choice;
    while (choice != 'q')
    {
        switch (choice)
        {
        case 'a':
            cin >> i;
            if (int_queue.Add(i))
                cout << i << " added" << endl;
            else
                cout << "Queue full" << endl;
            break;
        case 'r':
            if (int_queue.Remove(i))
                cout << i << " removed" << endl;
            else
                cout << "Queue empty" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cin >> choice;
    }
    return 0;
}
