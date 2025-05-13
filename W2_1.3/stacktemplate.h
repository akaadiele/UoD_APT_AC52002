#pragma once
#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H
#include "stack.h"


// Constructor
template <class Type>
Stack<Type> ::Stack(int stack_size) : Contents(new Type[stack_size]), Stack_size(stack_size), Index_of_top(-1)
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



// Top
template <class Type>
Type Stack<Type> ::Top() const
{
    if (Empty()) {
        Type x = Type();
        return x;
    }
    else {
        return Contents[Index_of_top];
    }
}

// PrintStack
template <class Type>
void Stack<Type> ::PrintStack() const
{
    for (int i = Index_of_top; i >= 0; i--) {
        std::cout << Contents[i] << std::endl;
    }
}

// Duplicate
template <class Type>
bool Stack<Type> ::Duplicate()
{
    if (Empty()) {
        return false;
    }
    else {
        Push(Contents[Index_of_top]);
        return true;
    }
}

// Delete
template <class Type>
bool Stack<Type> ::Delete(Type& del_element)
{
    if (Empty()) {
        return false;
    }

    bool found = false;
    for (int i = Index_of_top; i >= 0; i--) {
        if (Contents[i] == del_element) {
            for (int j = i; j < Index_of_top; j++) {
                Contents[j] = Contents[j + 1];
            }
            Index_of_top -= 1;
            found = true;
        }
    }
    return found;
}

// Overloaded output operator
template <class Type>
std::ostream& operator<<(std::ostream& o, const Stack<Type>& s)
{
    for (int i = s.Index_of_top; i >= 0; i--) {
        o << s.Contents[i] << std::endl;
    }
    return o;
}

#endif
