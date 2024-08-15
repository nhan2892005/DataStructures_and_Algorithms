#ifndef LINKEDList_H
#define LINKEDList_H

#include "standard.h"
#include "ListADT.h"
#include <iostream>
#include <string>
#include <exception>

template <typename PHUCNHAN>
class LinkedList : public ListADT<PHUCNHAN>
{
    private:
    struct Node {
        PHUCNHAN data;
        Node* next;
    };
    Node* head_node;
    Node* tail_node;
    int count;
    static constexpr PHUCNHAN none = PHUCNHAN();

    public:
    // ! Constructor
    LinkedList() : head_node(nullptr), tail_node(nullptr), count(0) {}
    LinkedList(const LinkedList& other) : head_node(nullptr), tail_node(nullptr), count(0) {
        Node* temp = other.head_node;
        while (temp != nullptr) {
            insert_tail(temp->data);
            temp = temp->next;
        }
    }
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node* temp = other.head_node;
            while (temp != nullptr) {
                insert_tail(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }
    LinkedList(int n, const PHUCNHAN& item) : head_node(nullptr), tail_node(nullptr), count(0) {
        for (int i = 0; i < n; i++) {
            insert_tail(item);
        }
    }
    ~LinkedList() {
        clear();
    }

    void clear() {
        while (head_node != nullptr) {
            Node* temp = head_node;
            head_node = head_node->next;
            delete temp;
        }
        tail_node = nullptr;
        count = 0;
    }

    // ! Operations
    void checkIndex(int& pos) const {
        // For negative index
        if (pos < 0) {
            pos = count + pos;
        }
        // For invalid index
        if (pos < 0 || pos >= count) {
            throw std::out_of_range("Invalid index");
        }
    }
    // * Insertion
    void insert_head(const PHUCNHAN& item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = head_node;
        head_node = newNode;
        if (tail_node == nullptr) {
            tail_node = head_node;
        }
        count++;
    }
    void insert_tail(const PHUCNHAN& item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;
        if (tail_node != nullptr) {
            tail_node->next = newNode;
        }
        tail_node = newNode;
        if (head_node == nullptr) {
            head_node = tail_node;
        }
        count++;
    }
    void insert_at(const PHUCNHAN& item, int pos) {
        checkIndex(pos);
        if (pos == 0) {
            insert_head(item);
        } else if (pos == count) {
            insert_tail(item);
        } else {
            Node* newNode = new Node;
            newNode->data = item;
            Node* temp = head_node;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            count++;
        }
    }

    void insert_after(const Node* &currentNode, const PHUCNHAN& key) {
        if (currentNode == nullptr) {
            throw std::out_of_range("Invalid node");
        }
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        if (currentNode == tail_node) {
            tail_node = newNode;
        }
        count++;
    }
    void insert_before(const Node* &currentNode, const PHUCNHAN& key) {
        if (currentNode == nullptr) {
            throw std::out_of_range("Invalid node");
        }
        if (currentNode == head_node) {
            insert_head(key);
        } else {
            Node* temp = head_node;
            while (temp->next != currentNode) {
                temp = temp->next;
            }
            insert_after(temp, key);
        }
    }

    // * Deletion
    void remove_head() {
        if (head_node == nullptr) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head_node;
        head_node = head_node->next;
        delete temp;
        count--;
        if (head_node == nullptr) {
            tail_node = nullptr;
        }
    }
    void remove_tail() {
        if (tail_node == nullptr) {
            throw std::out_of_range("List is empty");
        }
        if (head_node == tail_node) {
            delete head_node;
            head_node = tail_node = nullptr;
        } else {
            Node* temp = head_node;
            while (temp-> next != tail_node) {
                temp = temp->next;
            }
            delete tail_node;
            tail_node = temp;
            tail_node->next = nullptr;
        }
        count--;
    }
    void remove_at(int pos) {
        checkIndex(pos);
        if (pos == 0) {
            remove_head();
        } else if (pos == count - 1) {
            remove_tail();
        } else {
            Node* temp = head_node;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
            count--;
        }
    }
    int size() const {
        return count;
    }
    const PHUCNHAN& operator[](int pos) const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        checkIndex(pos);
        Node* temp = head_node;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    const PHUCNHAN& head() const {
        if (head_node == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return head_node->data;
    }
    const PHUCNHAN& tail() const {
        if (tail_node == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return tail_node->data;
    }
    bool isEmpty() const {
        return count == 0;
    }
    const PHUCNHAN& search(const PHUCNHAN& item) const {
        Node* temp = head_node;
        while (temp != nullptr) {
            if (temp->data == item) {
                return temp->data;
            }
            temp = temp->next;
        }
        return none;
    }
    void sort(int options=0, int type=0, int left=0, int right=0) {
        if (options == 0) {
            if (type == 0) {
                // sort(1, 0, 0, count - 1);
            } else {
                // sort(1, 1, 0, count - 1);
            }
        } else {
            if (type == 0) {
                // sort(0, 0, left, right);
            } else {
                // sort(0, 1, left, right);
            }
        }
    }
    std::string toString() const {
        std::string result = "Linked List {[";
        Node* temp = head_node;
        while (temp->next != nullptr) {
            result += std::to_string(temp->data) + ", ";
            temp = temp->next;
        }
        result += std::to_string(temp->data);
        result += "], size = " + std::to_string(count)+'}';
        return result;
    }
    void print(int left, int right) const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        checkIndex(left);
        checkIndex(right);
        Node* temp = head_node;
        for (int i = 0; i < left; i++) {
            temp = temp->next;
        }
        for (int i = left; i <= right; i++) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif