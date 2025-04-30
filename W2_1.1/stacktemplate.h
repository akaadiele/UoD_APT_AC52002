#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H
#include "stack.h"

#include <iostream>
using namespace std;


// Constructor
template <class Type>
Stack<Type> ::Stack(int stack_size) : Stack_size(stack_size), Contents(new Type[stack_size]), Index_of_top(-1), Front(0), Back(0)
{
}

// Destructor
template <class Type>
Stack<Type> :: ~Stack()
{
    delete[] Contents;
}

// Tests
template <class Type>
bool Stack<Type> ::Empty() const
{
    return (Index_of_top == -1) ? true : false;
}

template <class Type>
bool Stack<Type> ::Full() const
{
    return (Index_of_top == Stack_size - 1) ? true : false;
}

// Push
template <class Type>
bool Stack<Type> ::Push(const Type& new_element)
{
    if (Full()) {
        return false;
    }
    else {
        Index_of_top++;
        Contents[Index_of_top] = new_element;
        return true;
    }
}

// Pop
template <class Type>
bool Stack<Type> ::Pop(Type& top_element)
{
    if (Empty()) {
        return false;
    }
    else {
        top_element = Contents[Index_of_top];
        Index_of_top--;
        return true;
    }
}

// Additional functions

// A function Top which returns(as its value) the element on the top of the stack, but does not pop it from the stack.
template <class Type>
int Stack<Type>::Top()
{
	if (Empty())
		return false;
	else
	{
		return Contents[Index_of_top];
	}
}

// A function PrintStack which prints out a list of the elements in the stack, again without altering the stack at all.
template <class Type>
void Stack<Type>::PrintStack() {
	for (int i = 0; i <= Index_of_top; i++) {
		cout << Contents[i] << " ";
		//cout << Contents[i] << "(" << i <<")" << " ";
	}
}

// A function Duplicate which duplicates the top element, i.e.creates a new copy of the top element puts it on the top of the stack.
template <class Type>
void Stack<Type>::Duplicate() {
	int topElement = Top();
	Push(topElement);
}


// A function Delete which deletes all occurrences of a given integer from the stack.
template <class Type>
void Stack<Type>::Delete(Type delete_element) {
	int* newContents = new Type[Stack_size];
	int newIndex = -1;
	for (int i = 0; i <= Index_of_top; i++) {
		if (Contents[i] != delete_element) {
			newIndex++;
			newContents[newIndex] = Contents[i];
		}
	}
	delete[] Contents;
	Contents = newContents;
	Index_of_top = newIndex;
}


template <class Type>
bool Stack<Type>::Remove(Type& front_element) {
	if (Empty())
		return false;
	else
	{
		front_element = Contents[Front];
		//Front = (Front + 1) % (Stack_size + 1);

		//int* tempArr = new Type[Stack_size];
		//int tempIndex = -1;

		//tempArr = new Type[Stack_size - 1];
		//for (int i = 1; i < Stack_size; i++) {
		//		tempArr[i] = Contents[i];
		//}

		//delete[] Contents;
		//Contents = tempArr;
		//Index_of_top = tempIndex;


		int* tempContents = new Type[Stack_size];
		int tempIndex = -1;
		for (int i = 1; i <= Index_of_top; i++) {
				tempIndex++;
				tempContents[tempIndex] = Contents[i];
		}
		delete[] Contents;
		Contents = tempContents;
		Index_of_top = tempIndex;

		return true;
	}
}

#endif
