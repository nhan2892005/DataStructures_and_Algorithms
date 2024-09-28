#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;
        
        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};

/*
Implement methods add, size in template class DLinkedList (which implements List ADT) representing the doubly linked list with type T with the initialized frame. The description of each method is given in the code.
*/
template <class T>
DLinkedList<T>::~DLinkedList()
{
    clear();
}

template <class T>
void DLinkedList<T>::add(const T &e)
{
    Node *newNode = new Node(e);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
    if (index < 0 || index > count)
    {
        throw "Index is out of range";
    }
    if (index == count)
    {
        add(e);
        return;
    }
    Node *newNode = new Node(e);
    if (index == 0)
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    else
    {
        Node *prev = head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        Node *current = prev->next;
        newNode->next = current;
        newNode->previous = prev;
        prev->next = newNode;
        current->previous = newNode;
    }
    count++;
}

template <class T>
int DLinkedList<T>::size()
{
    return count;
}

/*
Implement methods get, set, empty, indexOf, contains in template class DLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
*/

template <class T>
T DLinkedList<T>::get(int index)
{
    if (index < 0 || index >= count)
    {
        throw "Index is out of range";
    }
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
    if (index < 0 || index >= count)
    {
        throw "Index is out of range";
    }
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    current->data = e;
}

template <class T>
bool DLinkedList<T>::empty()
{
    return count == 0;
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
{
    Node *current = head;
    for (int i = 0; i < count; i++)
    {
        if (current->data == item)
        {
            return i;
        }
        current = current->next;
    }
    return -1;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
    return indexOf(item) != -1;
}

/*
Implement Iterator class in class DLinkedList. 
*/

template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin)
{
    this->pList = pList;
    if (begin)
    {
        current = pList->head;
        index = 0;
    }
    else
    {
        current = NULL;
        index = pList->count;
    }
}

template <class T>
typename DLinkedList<T>::Iterator &DLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template <class T>
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current == NULL)
    {
        throw "No element to set";
    }
    current->data = e;
}

template <class T>
T &DLinkedList<T>::Iterator::operator*()
{
    if (current == NULL)
    {
        throw "No value to get";
    }
    return current->data;
}

template <class T>
bool DLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
    return this->current != iterator.current;
}

template <class T>
void DLinkedList<T>::Iterator::remove()
{
    if (current == NULL)
    {
        throw "No element to remove";
    }
    Node *del = current;
    current = current->next;
    pList->removeItem(del->data);
    index--;
}

template <class T>
typename DLinkedList<T>::Iterator &DLinkedList<T>::Iterator::operator++()
{
    if (current == NULL)
    {
        throw "Out of range";
    }
    current = current->next;
    index++;
    return *this;
}

template <class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int)
{
    Iterator iterator = *this;
    ++(*this);
    return iterator;
}

/*
Implement methods removeAt, removeItem, clear in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
*/

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= count)
    {
        throw "Index is out of range";
    }
    Node *del;
    if (index == 0)
    {
        del = head;
        head = head->next;
        if (head != NULL)
        {
            head->previous = NULL;
        }
        else
        {
            tail = NULL;
        }
    }
    else
    {
        Node *prev = head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        del = prev->next;
        prev->next = del->next;
        if (prev->next != NULL)
        {
            prev->next->previous = prev;
        }
        else
        {
            tail = prev;
        }
    }
    T data = del->data;
    delete del;
    count--;
    return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
{
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == item)
        {
            if (prev == NULL)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->previous = NULL;
                }
                else
                {
                    tail = NULL;
                }
            }
            else
            {
                prev->next = current->next;
                if (prev->next != NULL)
                {
                    prev->next->previous = prev;
                }
                else
                {
                    tail = prev;
                }
            }
            delete current;
            count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

template <class T>
void DLinkedList<T>::clear()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = tail = NULL;
    count = 0;
}

template <class T>
string DLinkedList<T>::toString()
{
    stringstream ss;
    ss << "[";
    Node *current = head;
    while (current != NULL)
    {
        ss << current->data;
        if (current->next != NULL)
        {
            ss << ", ";
        }
        current = current->next;
    }
    ss << "]";
    return ss.str();
}

int main()
{
    DLinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    cout << list.toString() << endl;
    list.add(0, 0);
    list.add(6, 6);
    cout << list.toString() << endl;
    list.removeAt(0);
    list.removeAt(6);
    cout << list.toString() << endl;
    list.removeItem(3);
    list.removeItem(5);
    cout << list.toString() << endl;
    list.clear();
    cout << list.toString() << endl;
    return 0;
}