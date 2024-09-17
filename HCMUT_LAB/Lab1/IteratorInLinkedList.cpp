#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>

template <class T>
class SLinkedList {
public:
    class Iterator;
    class Node;

private:
    Node* head;
    Node* tail;
    int count;

public:
    SLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty() const { return count == 0; }
    int size() const { return count; }
    void clear();
    T get(int index) const;
    void set(int index, const T &e);
    int indexOf(const T &item) const;
    bool contains(const T &item) const;
    std::string toString() const;
    SLinkedList(const SLinkedList &list);

    Iterator begin() { return Iterator(this, true); }
    Iterator end() { return Iterator(this, false); }

public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() : next(nullptr) {}
        Node(Node* next) : next(next) {}
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    class Iterator {
    private:
        SLinkedList<T>* pList;
        Node* current;
        int index;

    public:
        Iterator(SLinkedList<T>* pList, bool begin);

        Iterator& operator=(const Iterator& iterator);
        void set(const T& e);
        T& operator*();
        bool operator!=(const Iterator& iterator) const;

        // Prefix ++ overload
        Iterator& operator++();

        // Postfix ++ overload
        Iterator operator++(int);

        // Remove node
        void remove();
    };
};

// Destructor to clean up memory
template <class T>
SLinkedList<T>::~SLinkedList() {
    clear();
}

// Add element to the end of the list
template <class T>
void SLinkedList<T>::add(const T& e) {
    Node* newNode = new Node(e);
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    ++count;
}

// Add element at a specific index
template <class T>
void SLinkedList<T>::add(int index, const T& e) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Index out of range");
    }
    if (index == count) {
        add(e);
        return;
    }
    Node* newNode = new Node(e);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    } else {
        Node* prev = nullptr;
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            prev = current;
            current = current->next;
        }
        prev->next = newNode;
        newNode->next = current;
    }
    ++count;
}

// Remove element at a specific index
template <class T>
T SLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    Node* nodeToRemove = nullptr;
    T removedData;
    if (index == 0) {
        nodeToRemove = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* prev = nullptr;
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        if (current == tail) {
            tail = prev;
        }
        nodeToRemove = current;
    }
    removedData = nodeToRemove->data;
    delete nodeToRemove;
    --count;
    return removedData;
}

// Remove a specific item
template <class T>
bool SLinkedList<T>::removeItem(const T& removeItem) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == removeItem) {
            if (prev == nullptr) {
                head = current->next;
                if (head == nullptr) {
                    tail = nullptr;
                }
            } else {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;
                }
            }
            delete current;
            --count;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// Clear the list
template <class T>
void SLinkedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    count = 0;
}

// Get element at a specific index
template <class T>
T SLinkedList<T>::get(int index) const {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

// Set element at a specific index
template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->data = e;
}

// Find index of a specific item
template <class T>
int SLinkedList<T>::indexOf(const T& item) const {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        ++index;
        current = current->next;
    }
    return -1;
}

// Check if the list contains a specific item
template <class T>
bool SLinkedList<T>::contains(const T& item) const {
    return indexOf(item) != -1;
}

// Convert list to string representation
template <class T>
std::string SLinkedList<T>::toString() const {
    std::string result;
    Node* current = head;
    while (current != nullptr) {
        result += std::to_string(current->data) + " -> ";
        current = current->next;
    }
    result += "NULL";
    return result;
}

// Copy constructor
template <class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T>& list) : head(nullptr), tail(nullptr), count(0) {
    Node* current = list.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

// Iterator constructor
template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
    : pList(pList), current(nullptr), index(begin ? 0 : -1) {
    if (pList != nullptr) {
        if (begin) {
            current = pList->head;
            index = 0;
        } else {
            current = nullptr;
            index = pList->count;
        }
    }
}

// Assignment operator
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator) {
    if (this != &iterator) {
        this->pList = iterator.pList;
        this->current = iterator.current;
        this->index = iterator.index;
    }
    return *this;
}

// Set value of the current node
template <class T>
void SLinkedList<T>::Iterator::set(const T& e) {
    if (current == nullptr) {
        throw std::out_of_range("Setting value on end iterator");
    }
    current->data = e;
}

// Dereference operator
template <class T>
T& SLinkedList<T>::Iterator::operator*() {
    if (current == nullptr) {
        throw std::out_of_range("Dereferencing end iterator");
    }
    return current->data;
}

// Inequality operator
template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator) const {
    return this->current != iterator.current || this->index != iterator.index;
}

// Prefix ++ operator
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++() {
    if (current != nullptr) {
        current = current->next;
        ++index;
    }
    return *this;
}

// Postfix ++ operator
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

// Remove node
template <class T>
void SLinkedList<T>::Iterator::remove() {
    if (current == nullptr) {
        throw std::out_of_range("Removing node from end iterator");
    }

    Node* prev = nullptr;
    Node* temp = pList->head;
    
    // Find previous node
    if (temp == current) {
        pList->head = current->next;
    } else {
        while (temp != nullptr && temp->next != current) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            prev = temp;
        }
    }

    if (prev != nullptr) {
        prev->next = current->next;
    } else {
        pList->head = current->next;
    }

    if (pList->tail == current) {
        pList->tail = prev;
    }

    delete current;
    current = (prev != nullptr) ? prev->next : pList->head;
    pList->count--;
}
int main() {
    SLinkedList<int> list;
    
    int size = 10;
    for (int idx = 0; idx < size; ++idx) {
        list.add(idx);
    }
    
    // Test iterator
    SLinkedList<int>::Iterator it;
    int expvalue = 0;
    for (it = list.begin(); it != list.end(); ++it) {
        assert(*it == expvalue);
        expvalue += 1;
    }

    return 0;
}
