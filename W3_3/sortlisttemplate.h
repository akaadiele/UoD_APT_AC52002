#ifndef SORTLISTTEMPLATE_H
#define SORTLISTTEMPLATE_H
#include "sortlist.h"

template <class Type>
sortlist<Type>::~sortlist()
{
	delete[] Element;
}

template <class Type>
void sortlist<Type>::SetArray(Type sortarray[])
{

	for (int index = 0; index < ArraySize; index++)

		Element[index] = sortarray[index];

}

template <class Type>
void sortlist<Type>::GetArray(Type sortarray[])
{

	for (int index = 0; index < ArraySize; index++)

		sortarray[index] = Element[index];
}

template <class Type>
void sortlist<Type>::Swap(Type& A, Type& B)
{
	Type Temp = A;
	A = B;
	B = Temp;
}


template <class Type>
void sortlist<Type>::InsertionSort()
{
	// Code to go here
}

template <class Type>
void sortlist<Type>::SelectionSort()
{
	// Code to go here
}
#endif
