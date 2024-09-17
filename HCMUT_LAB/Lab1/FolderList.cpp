#include <iostream>
using namespace std;
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode() : val(0), next(nullptr) {}
    LLNode(int val, LLNode* next = 0) : val(val), next(next) {}
};

LLNode* findMiddle(LLNode* head) {
    LLNode* slow = head;
    LLNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

LLNode* reverseList(LLNode* head) {
    LLNode* prev = nullptr;
    LLNode* current = head;
    while (current != nullptr) {
        LLNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

LLNode* foldLinkedList(LLNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    LLNode* middle = findMiddle(head);
    LLNode* secondHalf = middle->next;
    middle->next = nullptr;

    secondHalf = reverseList(secondHalf);

    LLNode* firstHalf = head;
    LLNode* dummyHead = new LLNode(0);
    LLNode* current = dummyHead;

    while (firstHalf != nullptr && secondHalf != nullptr) {
        current->next = new LLNode(firstHalf->val + secondHalf->val);
        current = current->next;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    while (firstHalf != nullptr) {
        current->next = new LLNode(firstHalf->val);
        current = current->next;
        firstHalf = firstHalf->next;
    }
    
    LLNode* result = dummyHead->next;
    result = reverseList(result);
    delete dummyHead;
    return result;
}

// Hàm phụ để in danh sách liên kết
void printList(LLNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Ví dụ sử dụng
int main() {
    LLNode* head = new LLNode(9, new LLNode(5, new LLNode(7, new LLNode(5, new LLNode(0)))));
    LLNode* folded = foldLinkedList(head);
    printList(folded);
    return 0;
}
