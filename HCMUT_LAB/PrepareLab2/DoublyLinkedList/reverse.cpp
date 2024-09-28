/*
Given the head of a doubly linked list, two positive integer a and b where a <= b. Reverse the nodes of the list from position a to position b and return the reversed list

Note: the position of the first node is 1. It is guaranteed that a and b are valid positions. You MUST NOT change the val attribute in each node.

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

Constraint:
1 <= list.length <= 10^5
0 <= node.val <= 5000
1 <= left <= right <= list.length

Example 1:
Input: list = {3, 4, 5, 6, 7} , a = 2, b = 4
Output: 3 6 5 4 7

Example 2:
Input: list = {8, 9, 10}, a = 1, b = 3
Output: 10 9 8
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* reverse(ListNode* head, int a, int b) {
    if (!head || a == b) {
        return head;
    }

    ListNode* tmp = new ListNode(0, nullptr, head);
    ListNode* pre = tmp;

    for (int i = 1; i < a; i++) {
        pre = pre->right;
    }

    ListNode* cur = pre->right;
    ListNode* next_node;

    for (int i = a; i < b; i++) {
        next_node = cur->right;
        cur->right = next_node->right;
        next_node->right = pre->right;
        next_node->left = cur; 
        pre->right->left = next_node; 
        pre->right = next_node;
    }

    return tmp->right;
}

ListNode* createList(vector<int> v) {
    ListNode* head = new ListNode(v[0]);
    ListNode* cur = head;
    for (int i = 1; i < v.size(); i++) {
        cur->right = new ListNode(v[i]);
        cur->right->left = cur;
        cur = cur->right;
    }
    return head;
}

string printList(ListNode* head) {
    stringstream ss;
    while (head) {
        ss << head->val << " ";
        head = head->right;
    }
    return ss.str();
}

int main() {
    vector<int> v = {3, 4, 5, 6, 7};
    ListNode* head = createList(v);
    int a = 2, b = 4;
    cout << printList(reverse(head, a, b)) << endl;

    v = {8, 9, 10};
    head = createList(v);
    a = 1, b = 3;
    cout << printList(reverse(head, a, b)) << endl;

    return 0;
}