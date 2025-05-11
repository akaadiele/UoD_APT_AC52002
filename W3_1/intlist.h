#ifndef INTLIST
#define INTLIST
#include <iostream>
using namespace std;

// Basic list for integers, minimal functionality

class Intlist
{
private:
    class Node
    {
    public:
        int Element;
        Node* Next;

        Node() : Next(nullptr) {}
        Node(int data, Node* pnode = nullptr) :
            Element(data), Next(pnode) {
        }
    };

    Node* Head;
public:
    Intlist();
    ~Intlist();
    bool Empty() const;
    bool Insert(const int& new_element);
    bool Delete(const int& del_element);
    void Print(ostream& out_stream) const;
    bool Delete_last();
    bool Swap_first_two();
    void Swap_elements();
    void Append(const Intlist& list2);
    Intlist operator+(const Intlist& list2) const;
};

ostream& operator<<(ostream& out_stream,
    const Intlist& out_list);
#endif
