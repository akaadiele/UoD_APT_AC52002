#ifndef STACK_QUEUE_TEMPLATE_H
#define STACK_QUEUE_TEMPLATE_H
#include "stack_queue_def.h"

#include <iostream>
#include <iomanip>
using namespace std;


// Constructor
template <class Type>
Stack<Type> ::Stack(int stack_size) : stackSize(stack_size), contents(new Type[stack_size]), indexOfTop(-1), indexOfFront(0) {
}

// Destructor
template <class Type>
Stack<Type> :: ~Stack()
{
	//delete[] contents;
}

// Member functions
template <class Type>
bool Stack<Type> ::empty() const
{
	return (indexOfTop == -1) ? true : false;
}

template <class Type>
bool Stack<Type> ::full() const
{
	return (indexOfTop == stackSize - 1) ? true : false;
}

// push
// push new element onto the stack at the top
template <class Type>
bool Stack<Type> ::push(const Type& new_element)
{
	if (full()) {
		return false;
	}
	else {
		indexOfTop++;
		contents[indexOfTop] = new_element;
		return true;
	}
}

// pop (LIFO)
// pop element from the stack at the top
template <class Type>
bool Stack<Type> ::pop(Type& top_element)
{
	if (empty()) {
		return false;
	}
	else {
		top_element = contents[indexOfTop];
		indexOfTop--;
		return true;
	}
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// remove front element (FIFO)
template <class Type>
bool Stack<Type>::remove(Type& front_element) {
	//bool Stack<Type>::remove() {
	if (empty())
		return false;
	else
	{
		front_element = contents[indexOfFront];

		Type* tempContents = new Type[stackSize];
		int tempIndex = -1;
		for (int i = 1; i <= indexOfTop; i++) {
			tempIndex++;
			tempContents[tempIndex] = contents[i];
		}
		delete[] contents;
		contents = tempContents;
		indexOfTop = tempIndex;

		return true;
	}
}

// add
// Add new element to the stack at the bottom
template <class Type>
bool Stack<Type>::add(const Type& new_element) {
	//if (full()) {
	//	return false;
	//}
	//else {
	//	for (int i = indexOfTop; i >= 0; i--) {
	//		contents[i + 1] = contents[i];
	//	}
	//	indexOfTop++;
	//	contents[indexOfFront] = new_element;
	//	return true;
	//}

	if (full())
		return false;
	else
	{
		Type* tempContents = new Type[stackSize];
		tempContents[0] = new_element;

		int tempIndex = 1;
		for (int i = 0; i <= indexOfTop; i++) {
			tempIndex++;
			tempContents[tempIndex] = contents[i];
		}
		delete[] contents;
		contents = tempContents;
		indexOfTop = tempIndex;


		//// ----
		//Contents[indexOfFront] = new_element;
		//Back = (Back + 1) % (Queue_size + 1);

		return true;
	}
}


// top
template <class Type>
Type Stack<Type>::top()
{
	return contents[indexOfTop];
}

// bottom
template <class Type>
Type Stack<Type>::bottom()
{
	return contents[indexOfFront];
}

// printStack
template <class Type>
void Stack<Type>::printStack() {
	for (int i = 0; i <= indexOfTop; i++) {
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << setw(15) << left << contents[i].printStock() << " " << endl;
	}
}


template <class Type>
int Stack<Type>::getIndexOfTop() {
	return indexOfTop;
}

template <class Type>
int Stack<Type>::getStockStack() {
	return stackSize;
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------


// Delete all occurrences
template <class Type>
void Stack<Type>::deleteAllOccurence(Type delete_element) {
	int* newContents = new Type[stackSize];
	int newIndex = -1;
	for (int i = 0; i <= indexOfTop; i++) {
		if (contents[i] != delete_element) {
			newIndex++;
			newContents[newIndex] = contents[i];
		}
	}
	delete[] contents;
	contents = newContents;
	indexOfTop = newIndex;
}


// duplicate
template <class Type>
void Stack<Type>::duplicate() {
	int topElement = top();
	push(topElement);
}


#endif
#pragma once
