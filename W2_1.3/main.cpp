#include "stacktemplate.h"
#include <iostream>
using namespace std;

int main() {
    Stack<int> int_stack(10);
    int object;
    cout << "Enter a sequence of integers, 0 to finish" << endl;
    cin >> object;

    while (object != 0) {
        int_stack.Push(object);
        cin >> object;
    }

    cout << endl << "Stack contents:" << endl;
    int_stack.PrintStack();
    cout << endl;

    cout << "Top Element: " << int_stack.Top() << endl;

    cout << "Duplicating top element" << endl;
    int_stack.Duplicate();

    cout << "Stack contents:" << endl;
    cout << int_stack;
    cout << endl;

    cout << "Enter an element to delete: ";
    cin >> object;

    if (int_stack.Delete(object)) {
        cout << object << " deleted!" << endl;
    }
    else {
        cout << object << " could not be deleted" << endl;
    }

    cout << endl << "Stack contents:" << endl;
    cout << int_stack;
    cout << endl;

    return 0;
}
