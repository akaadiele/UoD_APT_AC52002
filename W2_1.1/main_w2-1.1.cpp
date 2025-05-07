#include "stacktemplate.h"
#include <iostream>
using namespace std;

int main() {
    Stack<int> int_stack(10);
    int object;
    cout << "Enter a sequence of integers, 0 to finish" << endl;
    cin >> object;

    while (object != 0)
    {
        int_stack.Push(object);
        cin >> object;
    }

    //cout << endl << "Stack contents:" << endl;
    //while (!int_stack.Empty())
    //{
    //    int_stack.Pop(object);
    //    cout << object << endl;
    //}


    //Using the additional functions
    
 //   int topElement = int_stack.Top();
 //   if (topElement)
 //   {
 //       cout << "\nThe top element is: " << int_stack.Top() << endl;
 //   }
 //   else
 //   {
 //       cout << "\nThe stack is empty." << endl;
 //   }


    cout << endl << "\nStack contents:" << endl;
    int_stack.PrintStack();


 //   int_stack.Duplicate();

 //   cout << endl << "\nStack contents after duplicate:" << endl;
 //   int_stack.PrintStack();
	//cout << endl;


    //int delVal;
    //cout << "\nEnter an integer to delete:" << endl;
    //cin >> delVal;
    //int_stack.Delete(delVal);

    //cout << endl << "\nStack contents after delete:" << endl;
    //int_stack.PrintStack();

    
    cout << "\nPopping item ... :" << endl;
    int_stack.Pop(object);
    cout << object << " popped" << endl;
    cout << endl << "\nStack contents after pop:" << endl;
    int_stack.PrintStack();

	cout << "\nEnter item to push :" << endl;
    cin >> object;
    int_stack.Push(object);
    cout << endl << "\nStack contents after push:" << endl;
    int_stack.PrintStack();


    int removeVal;
    cout << "\nRemoving item ... :" << endl;
    if (int_stack.Remove(removeVal))
        cout << removeVal << " removed" << endl;
    else
        cout << "Queue empty" << endl;
    
    cout << endl << "\nStack contents after removing '" << removeVal << "' :" << endl;
    int_stack.PrintStack();


    return 0;
}