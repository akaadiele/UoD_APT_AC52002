#ifndef STACK_QUEUE_DEF_H
#define STACK_QUEUE_DEF_H

#include <string>

template <class Type>
class Stack
{
private:
    int stackSize;
    int indexOfTop;
    int indexOfFront;

public:
    Stack(int stackSize = 10);
    ~Stack();

    Type* contents;

    bool empty() const;
    bool full() const;

    bool push(const Type& new_element);
    bool pop(Type& top_element);
    bool remove(Type& front_element);
    bool add(const Type& new_element);
    
    Type top();
    Type bottom();

    void printStack();
    int getIndexOfTop();
    int getStockStack();

    void deleteAllOccurence(Type delete_element);
    void duplicate();
};

#endif
#pragma once
