#ifndef STACK_H
#define STACK_H

#include <iostream>

// Declare templates (required for templated friend function)
template <class Type> class Stack;
template <class Type> std::ostream& operator<<(std::ostream&, const Stack<Type>&);

template <class Type>
class Stack
{
private:
    Type* Contents;
    int Stack_size;
    int Index_of_top;
public:
    Stack(int stack_size = 10);
    ~Stack();
    bool Empty() const;
    bool Full() const;
    bool Pop(Type& top_element);
    bool Push(const Type& new_element);

    Type Top() const;
    void PrintStack() const;
    bool Duplicate();
    bool Delete(Type& del_element);

    friend std::ostream& operator<< <Type>(std::ostream&, const Stack<Type>&);
};

#endif
