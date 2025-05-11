#include "intlist.h"

// Constructor
Intlist::Intlist() : Head(nullptr)
{
}

// Destructor

Intlist :: ~Intlist()
{
	Node* temp;
	while (Head != nullptr)
	{
		temp = Head;
		Head = Head->Next;
		delete temp;
	}
}

// Tests

bool Intlist::Empty() const
{
	return (Head == nullptr) ? true : false;
}

// Insert (simple insert at beginning)

bool Intlist::Insert(const int& new_element)
{
	Node* new_node;
	new_node = new Node;
	new_node->Element = new_element;
	new_node->Next = Head;
	Head = new_node;
	return true;
}

// Delete

bool Intlist::Delete(const int& del_element)
{
	Node* temp;
	Node* previous;

	if (Empty())
		return false;
	else if (Head->Element == del_element)
	{
		temp = Head;
		Head = Head->Next;
		delete temp;
		return true;
	}
	else if (Head->Next == nullptr)
		return false;
	else
	{
		previous = Head;
		temp = Head->Next;
		while ((temp->Element != del_element) &&
			(temp->Next != nullptr))
		{
			previous = temp;
			temp = temp->Next;
		}
		if (temp->Element == del_element)
		{
			previous->Next = temp->Next;
			delete temp;
			return true;
		}
		else  // list exhausted
			return false;
	}
}

// Print

void Intlist::Print(ostream& out_stream) const
{
	Node* temp;
	temp = Head;
	while (temp != nullptr)
	{
		out_stream << temp->Element << " ";
		temp = temp->Next;
	}
}

// Overloaded output operator

ostream& operator<<(ostream& out_stream,
	const Intlist& out_list)
{
	out_list.Print(out_stream);
	return out_stream;
}

int Intlist::First() const
{
	if (Empty())
		return 0;
	else
		return Head->Element;
}

void Intlist::Doublelist()
{
	Node* temp = Head;
	while (temp != nullptr)
	{
		temp->Element *= 2;
		temp = temp->Next;
	}
}

int Intlist::Count_elements() const
{
	int count = 0;
	Node* temp = Head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->Next;
	}
	return count;
}

int Intlist::Position(int item) const
{
	int count = 1;
	Node* temp = Head;
	while ((temp != nullptr) && (temp->Element != item))
	{
		temp = temp->Next;
		count++;
	}
	if (temp == nullptr)
		return 0;
	else
		return count;
}

int Intlist::Occurs(int item) const
{
	int count = 0;
	Node* temp = Head;
	while (temp != nullptr)
	{
		if (temp->Element == item)
			count++;
		temp = temp->Next;
	}
	return count;
}

void Intlist::Insert_at_end(const int& new_element)
{
	Node* new_node = new Node;
	new_node->Element = new_element;
	if (Empty())
		Head = new_node;
	else
	{
		Node* temp = Head;
		while (temp->Next != nullptr)
			temp = temp->Next;
		temp->Next = new_node;
	}
}


