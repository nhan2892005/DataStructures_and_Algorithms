#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    list.insert_head(1);
    list.insert_head(2);
    list.insert_head(3);
    list.insert_head(4);
    list.insert_head(5);

    std::cout << list.toString() << std::endl;
    return 0;
}