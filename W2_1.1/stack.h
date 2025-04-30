#ifndef STACK_H
#define STACK_H

template <class Type>
class Stack
{
private:
    Type* Contents;
    int Stack_size;
    int Index_of_top;
    int Front, Back;
public:
    Stack(int stack_size = 10);
    ~Stack();
    bool Empty() const;
    bool Full() const;
    bool Pop(Type& top_element);
    bool Push(const Type& new_element);

    //Additional functions
    int Top();
    void PrintStack();
    void Duplicate();
    void Delete(Type delete_element);
    bool Remove(Type& front_element);
};

#endif
