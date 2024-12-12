#include "DoublyLinkedList.h"
#include "DataLog.h"
#include <iostream>

using namespace std;

void testDLL() {
    // Test 1
    DLinkedList<int> list;
    int size = 10;
    for(int idx=0; idx < size; idx++){
    list.add(idx);
    }
    cout << list.toString();

    // Test 2
    DLinkedList<int> list2;
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list2.add(0, idx);
    }
    cout << list2.toString();

    // Test 3
    DLinkedList<int> list3;
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list3.add(idx);
    }
    for(int idx=0; idx < size; idx++){
        cout << list3.get(idx) << " |";
    }

    // Test 4
    DLinkedList<int> list4;
    int size = 10;
    int value[] = {2,5,6,3,67,332,43,1,0,9};
    for(int idx=0; idx < size; idx++){
        list4.add(idx);
    }
    for(int idx=0; idx < size; idx++){
        list4.set(idx, value[idx]);
    }
    cout << list4.toString();

    // Test 5
    DLinkedList<int> list5;
    int size = 10;
    int value[] = {2,5,6,3,67,332,43,1,0,9};

    for(int idx=0; idx < size; idx++){
        list5.add(value[idx]);
    }
    list5.removeAt(0);
    cout << list5.toString();
}

void testDataLog() {
    // Test 1
    DataLog log(10);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.addCurrentState(15);
    log.undo();
    log.printLog();

    // Test 2
    DataLog log2(10);
    log2.save();
    log2.addCurrentState(15);
    log2.save();
    log2.addCurrentState(15);
    log2.save();
    log2.subtractCurrentState(5);
    log2.printLog();
}

int main() {

}