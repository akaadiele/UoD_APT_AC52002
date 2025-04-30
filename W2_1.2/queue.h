#ifndef QUEUE_H
#define QUEUE_H

// Standard integer queue

class Queue
{
private:
	int* Contents;
	int Queue_size;
	int Front, Back;
public:
	Queue(int queue_size = 10);
	~Queue();
	bool Empty() const;
	bool Full() const;
	bool Remove(int& front_element);
	bool Add(const int& new_element);
};
#endif
