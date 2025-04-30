//#include "stack.h"
//
//#include <iostream>
//using namespace std;
//
//
//
//// Constructor
//
//Stack::Stack() : Index_of_top(-1)
//{
//}
//
//// Tests
//bool Stack::Empty() const
//{
//	return (Index_of_top == -1) ? true : false;
//}
//
//bool Stack::Full() const
//{
//	return (Index_of_top == MAXSTACKSIZE - 1) ? true : false;
//}
//
//// Pop and Push
//
//bool Stack::Pop(int& top_element)
//{
//	if (Empty())
//		return false;
//	else
//	{
//		top_element = Contents[Index_of_top];
//		Index_of_top--;
//		return true;
//	}
//}
//
//bool Stack::Push(const int& new_element)
//{
//	if (Full())
//		return false;
//	else
//	{
//		Index_of_top++;
//		Contents[Index_of_top] = new_element;
//		return true;
//	}
//}
//
//
//
//// Additional functions
//
//// A function Top which returns(as its value) the element on the top of the stack, but does not pop it from the stack.
//int Stack::Top()
//{
//	if (Empty())
//		return false;
//	else
//	{
//		return Contents[Index_of_top];
//	}
//}
//
//// A function PrintStack which prints out a list of the elements in the stack, again without altering the stack at all.
//void Stack::PrintStack() {
//	for (int i = 0; i <= Index_of_top; i++) {
//		cout << Contents[i] << " ";
//	}
//}
//
//// A function Duplicate which duplicates the top element, i.e.creates a new copy of the top element puts it on the top of the stack.
//void Stack::Duplicate() {
//	int topElement = Top();
//	Push(topElement);
//}
//
//
//// A function Delete which deletes all occurrences of a given integer from the stack.
//void Stack::Delete(int delete_element) {
//	//int tempStack[MAXSTACKSIZE];
//	//int tempIndex = -1;
//	//int currentElement;
//	//while (Pop(currentElement)) {
//	//	if (currentElement != delete_element) {
//	//		tempIndex++;
//	//		tempStack[tempIndex] = currentElement;
//	//	}
//	//}
//	//for (int i = 0; i <= tempIndex; i++) {
//	//	Push(tempStack[i]);
//	//}
//
//	int tempStack[MAXSTACKSIZE];
//	int tempIndex = -1;
//	int currentElement;
//	while (Pop(currentElement)) {
//		if (currentElement != delete_element) {
//			tempIndex++;
//			tempStack[tempIndex] = currentElement;
//		}
//	}
//	for (int i = tempIndex; i >= 0; i--) {
//		Push(tempStack[i]);
//	}
//}