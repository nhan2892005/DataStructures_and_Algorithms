/*
Class LLNode is used to store a node in a singly linked list, described on the following:

class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next);
}
Where val is the value of node, next is the pointer to the next node.

Request: Implement function:

LLNode* addLinkedList(LLNode* l0, LLNode* l1);
Where l0, l1 are two linked lists represented positive integers, each node is a digit, the head is the least significant digit (the value of each node is between 0 and 9, the length of each linked list is between 0 and 100000). This function returns the linked list representing the sum of the two integers.

Example:

Given l0 = [2, 3] (representing 32) and l1 = [1, 8] (representing 81). The result would be l0 = [3, 1, 1] (representing 32 + 81 = 113).

Note:

In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.

For example:

Test	
int arr1[] = {2, 9};
int arr2[] = {0, 5};
LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
LLNode* newhead = addLinkedList(head1, head2);
LLNode::printList(newhead);
head1->clear();
head2->clear();
newhead->clear();

Result
[2, 4, 1]
*/

#include "LLNode.h"

LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    int cache = 0;
    LLNode* dummy = new LLNode(0);
    LLNode* current = dummy;
    LLNode* lhs = l0;
    LLNode* rhs = l1;
    while (lhs != nullptr || rhs != nullptr) {
        int lhs_val = (lhs != nullptr) ? lhs->val : 0; 
        int rhs_val = (rhs != nullptr) ? rhs->val : 0;

        int sum = lhs_val + rhs_val + cache;
        cache = sum / 10; 
        current->next = new LLNode(sum % 10); 

        current = current->next;
        if (lhs != nullptr) lhs = lhs->next; 
        if (rhs != nullptr) rhs = rhs->next; 
    }

    if (cache > 0) {
        current->next = new LLNode(cache);
    }
    return dummy->next;
}

int main() {
    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead);
    head1->clear();
    head2->clear();
    newhead->clear();
    return 0;
}