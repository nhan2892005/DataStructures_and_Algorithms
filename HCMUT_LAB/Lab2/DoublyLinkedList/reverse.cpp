/*
Given the head of a doubly linked list, two positive integer a and b where a <= b. Reverse the nodes of the list from position a to position b and return the reversed list

Note: the position of the first node is 1. It is guaranteed that a and b are valid positions. You MUST NOT change the val attribute in each node.
*/
#include <iostream>
#include <unordered_map>
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

void test1() {
    int size;
    cin >> size;
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue);
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;
}

int test2() {
    int size;
    cin >> size;
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue);
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;
}

int main() {
    test1();
    test2();
    return 0;
}
