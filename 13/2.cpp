#include <iostream>
using namespace std;

template <class T> 
class linkList;
template <class T> 
ostream &operator<<(ostream &os, const linkList<T> &obj);

template <class T>
class linkList
{
    friend ostream &operator<< <>(ostream &os, const linkList<T> &obj);

protected:
    void makeEmpty();
    class Node
    {
    public:
        T data;
        Node *next;
        Node(const T &x, Node *N = nullptr)
            :data{ x }, next{ N } { }
        Node() :next{ nullptr } { }
    };
    Node *head;

public:
    linkList() :head{ new Node } { }
    ~linkList() { makeEmpty(); delete head; }
};

template <class T>
void linkList<T>::makeEmpty()
{
    Node *p = head->next, *q;
    head->next = nullptr;
    while (p != nullptr)
    {
        q = p->next;
        delete p;
        p = q;
    }
}

template <class T>
ostream &operator<<(ostream &os, const linkList<T> &obj)
{
    typename linkList<T>::Node *q = obj.head->next;
    while (q->next != nullptr)
    {
        os << q->data << ' ';
        q = q->next;
    }
    return os << q->data;
}

template <class T>
class myQueue : public linkList<T>
{
public:
    void push(const T &data);
    T pop();
    T &first();
};

template <class T>
void myQueue<T>::push(const T &data)
{
    typename linkList<T>::Node *p = new typename linkList<T>::Node{ data };
    typename linkList<T>::Node *q = this->head;
    while (q->next != nullptr)
        q = q->next;
    q->next = p;
}

template <class T>
T myQueue<T>::pop()
{
    typename linkList<T>::Node *p = this->head->next;
    this->head->next = p->next;
    T data = p->data;
    delete p;
    return data;
}

template <class T>
T &myQueue<T>::first()
{
    return this->head->next->data;
}