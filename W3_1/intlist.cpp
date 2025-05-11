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

bool Intlist::Delete_last()
{
	if (Empty())
		return false;
	else if (Head->Next == nullptr)
	{
		delete Head;
		Head = nullptr;
		return true;
	}
	else
	{
		Node* temp = Head;
		while (temp->Next->Next != nullptr)
		{
			temp = temp->Next;
		}
		delete temp->Next;
		temp->Next = nullptr;
		return true;
	}
}

bool Intlist::Swap_first_two()
{
	if ((Head == nullptr) || (Head->Next == nullptr))
		return false;
	else
	{
		Node* first = Head;
		Node* second = first->Next;
		first->Next = second->Next;
		second->Next = first;
		Head = second;
		return true;
	}
}

void Intlist::Swap_elements()
{
	if ((Head != nullptr) && (Head->Next != nullptr))
	{
		// Swap first two nodes
		Node* first = Head;
		Node* second = first->Next;
		first->Next = second->Next;
		second->Next = first;
		Head = second;

		// Set temporary pointer to point to second node (the pointer to this is still "first")
		Node* temp = first;
		// Then proceed as before, but now pointer to rest of list is temp->Next rather than Head
		while ((temp->Next != nullptr) && (temp->Next->Next != nullptr))
		{
			first = temp->Next;
			second = first->Next;
			first->Next = second->Next;
			second->Next = first;
			temp->Next = second;
			temp = first;
		}
	}
}

void Intlist::Append(const Intlist& list2)
{
	Node* marker;
	Node* old_marker;
	Node* temp_head;

	// First make copy of list2, with a temporary pointer pointing to its first node
	old_marker = list2.Head;
	if (old_marker == nullptr)
		temp_head = nullptr;
	else
	{
		temp_head = new Node(old_marker->Element, nullptr);
		marker = temp_head;
		old_marker = old_marker->Next;
		while (old_marker != nullptr)
		{
			marker->Next =
				new Node(old_marker->Element, nullptr);
			old_marker = old_marker->Next;
			marker = marker->Next;
		}
	}
	// Then make last node of list point to first node of this copy.
	if (Empty())
		Head = temp_head;
	else
	{
		Node* temp = Head;
		while (temp->Next != nullptr)
			temp = temp->Next;
		temp->Next = temp_head;
	}
}

Intlist Intlist::operator+(const Intlist& list2) const
{
	Intlist sum;
	sum.Append(*this);
	sum.Append(list2);
	return sum;
}
