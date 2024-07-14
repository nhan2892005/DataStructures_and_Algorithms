#include <iostream>

using std::cout;
using std::endl;

struct Node {
    int data;
    Node* next;
    Node(): data(0), next(nullptr){}
    Node(int val, Node* next = nullptr): data(val), next(next){}
};
class MyLinkedList {
private:
    Node* head;
    int size;
    bool checkIndex(int idx) const{
        return 0 <= idx && idx <= this->size - 1;
    }
public:
    MyLinkedList():head(nullptr), size(0) {}
    
    int get(int index) {
        if (!checkIndex(index)) return -1;
        Node* tmp = this->head;
        int count = 0;
        while (count++ < index) {
            tmp = tmp->next;
        }
        return tmp->data;
    }
    
    void addAtHead(int val) {
        if (!this->head) {this->head = new Node(val); ++this->size; return;}
        Node* newNode = new Node(val, this->head);
        this->head = newNode;
        ++size;
    }
    
    void addAtTail(int val) {
        if (!this->head) {this->head = new Node(val); ++this->size; return;}
        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new Node(val);
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {addAtHead(val); return;}
        if (index == this->size) {addAtTail(val); return;}
        if (!checkIndex(index)) return;

        Node* tmp = head;
        int count = 0;

        while (count < index - 1) {
            tmp = tmp->next;
            ++count;
        }

        Node* newNode = new Node(val, tmp->next);

        tmp->next = newNode;

        ++size;
    }
    
    void deleteAtIndex(int index) {
        if (!checkIndex(index)) return;
        if (index == 0) {Node* tmp = head; head = head->next; delete tmp; --size; return;}

        Node* tmp = head;
        int count = -1;
        while (++count < index - 1){
            tmp = tmp->next;
        }
        Node* deleteNode = tmp->next;
        tmp->next = tmp->next->next;
        delete deleteNode;
        --size;
    }
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    cout << obj->get(1) << endl;
    obj->deleteAtIndex(1);
    cout << obj->get(1) << endl;
    return 0;
}