#ifndef LLNODE_H
#define LLNODE_H

#include <iostream>
using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode() {
        val = 0;
        next = nullptr;
    }
    LLNode(int val, LLNode* next) {
        this->val = val;
        this->next = next;
    }
    static LLNode* createWithIterators(int* begin, int* end) {
        LLNode* head = new LLNode();
        LLNode* current = head;
        for (int* it = begin; it != end; ++it) {
            current->next = new LLNode(*it, nullptr);
            current = current->next;
        }
        return head->next;
    }
    static void printList(LLNode* head) {
        cout << "[";
        while (head != nullptr) {
            cout << head->val;
            head = head->next;
            if (head != nullptr) {
                cout << ", ";
            }
        }
        cout << "]";
    }
    void clear() {
        LLNode* current = this;
        while (current != nullptr) {
            LLNode* next = current->next;
            delete current;
            current = next;
        }
    }
};

#endif // LLNODE_H