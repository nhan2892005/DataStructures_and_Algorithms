#include <iostream>
using namespace std;
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode() : val(0), next(nullptr) {}
    LLNode(int val, LLNode* next = 0) : val(val), next(next) {}
};

// Hàm tính chiều dài của danh sách liên kết
int getLength(LLNode* head) {
    int length = 0;
    LLNode* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }
    return length;
}

LLNode* rotateLinkedList(LLNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    int length = getLength(head);
    k = k % length;

    if (k == 0) {
        return head;
    }

    LLNode* prev = nullptr;
    LLNode* curr = head;
    
    for (int i = 0; i < length - k; ++i) {
        prev = curr;
        curr = curr->next;
    }

    LLNode* newHead = curr;
    prev->next = nullptr;

    LLNode* tail = newHead;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head;

    return newHead;
}

void printList(LLNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Ví dụ sử dụng
int main() {
    LLNode* head = new LLNode(1, new LLNode(2, new LLNode(3, new LLNode(4, new LLNode(5)))));
    int k = 2;
    LLNode* result = rotateLinkedList(head, k);
    printList(result);
    return 0;
}
