#include <iostream>

#include "alist.h"

int main(int agrc, char* argv[]){
    AList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(10);

    for (int i = 0; i < list.size(); i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    list.insert(100, 5);
    for (int i = 0; i < list.size(); i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    list.push_back(200);
    for (int i = 0; i < list.size(); i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    // check bool
    std::cout << std::boolalpha;
    std::cout << "Is list empty? " << list.empty() << std::endl;
    std::cout << "Is list full? " << list.isFull() << std::endl;
    std::cout << "Is list contains 100? " << list.contains(100) << std::endl;
    std::cout << "Is list sorted? " << list.isSorted() << std::endl;

    // get size
    std::cout << "Size of list: " << list.size() << std::endl;

    // get element
    std::cout << "Element at index 5: " << list[5] << std::endl;

    // delete element
    list.deleteElement(5);
    for (int i = 0; i < list.size(); i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    // clear list
    list.clear();
    std::cout << "Is list empty? " << std::boolalpha << list.empty() << std::endl;

    return 0;
}