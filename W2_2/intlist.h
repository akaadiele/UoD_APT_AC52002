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
        Node(int data, Node* pnode = nullptr) : Element(data), Next(pnode) {
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
    int First() const;
    void Doublelist();
    int Count_elements() const;
    int Position(int item) const;
    int Occurs(int item) const;
    void Insert_at_end(const int& new_element);
};

ostream& operator<<(ostream& out_stream,
    const Intlist& out_list);
#endif
