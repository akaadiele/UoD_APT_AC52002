//#include "stack.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    Stack int_stack;
//    int object;
//
//    cout << "Enter a sequence of integers, 0 to finish" << endl;
//
//    cin >> object;
//    while (object != 0)
//    {
//        int_stack.Push(object);
//        cin >> object;
//    }
//
//    //cout << endl << "Stack contents:" << endl;
//    //while (!int_stack.Empty())
//    //{
//    //    int_stack.Pop(object);
//    //    cout << object << endl;
//    //}
//    
//
//    int topElement = int_stack.Top();
//	if (topElement)
//	{
//        cout << "\nThe top element is: " << int_stack.Top() << endl;
//	}
//	else
//	{
//		cout << "\nThe stack is empty." << endl;
//	}
//	
//    
//    cout << endl << "\nStack contents:" << endl;
//    int_stack.PrintStack();
//    
//    int_stack.Duplicate();
//
//    cout << endl << "\nStack contents after duplicate:" << endl;
//    int_stack.PrintStack();
//
//    int delVal;
//    cout << "\nEnter an integer to delete:" << endl;
//	cin >> delVal;
//    int_stack.Delete(delVal);
//
//    cout << endl << "\nStack contents after delete:" << endl;
//    int_stack.PrintStack();
//
//    return 0;
//}
