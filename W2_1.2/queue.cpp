#include "queue.h"

// Constructor

Queue::Queue(int queue_size) :
    Queue_size(queue_size),
    Contents(new int[queue_size + 1]),
    Front(0), Back(0)
{
}

// Destructor

Queue :: ~Queue()
{
    delete[] Contents;
}

// Tests

bool Queue::Empty() const
{
    return (Front == Back) ? true : false;
}

bool Queue::Full() const
{
    return ((1 + Back) % (Queue_size + 1) == Front) ? true : false;
}

// Remove and Add

bool Queue::Remove(int& front_element)
{
    if (Empty())
        return false;
    else
    {
        front_element = Contents[Front];
        Front = (Front + 1) % (Queue_size + 1);
        return true;
    }
}

bool Queue::Add(const int& new_element)
{
    if (Full())
        return false;
    else
    {
        Contents[Back] = new_element;
        Back = (Back + 1) % (Queue_size + 1);
        return true;
    }
}
