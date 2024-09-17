#include <iostream>
#include <stack>
using namespace std;
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode() : val(0), next(nullptr) {}
    LLNode(int val, LLNode* next = 0) : val(val), next(next) {}
};

LLNode* replaceFirstGreater(LLNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    std::stack<LLNode*> s;
    LLNode* curr = head;

    while (curr != nullptr) {
        while (!s.empty() && s.top()->val <= curr->val) {
            LLNode* topNode = s.top();
            s.pop();
            topNode->val = curr->val;
        }
        
        s.push(curr);
        curr = curr->next;
    }

    while (!s.empty()) {
        LLNode* topNode = s.top();
        s.pop();
        topNode->val = 0;
    }

    return head;
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
    LLNode* head = new LLNode(0, new LLNode(3, new LLNode(2, new LLNode(1, new LLNode(5)))));
    LLNode* result = replaceFirstGreater(head);
    printList(result);
    return 0;
}
