#include "DoublyLinkedList.h"

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