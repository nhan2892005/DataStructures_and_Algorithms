#include <iostream>
#include <cstdlib>

#include "ArrayList.h"

int main() {
    // Create an ArrayList object
    ArrayList<int> list;
    // Insert some elements by random
    int length = 10;
    for (int i = 0; i < length; i++) {
        list.insert_tail(rand() % 100);
    }
    std::cout << list.toString() << std::endl;

    // Test operations
    // Insert head
    list.insert_head(100);
    // Insert tail
    list.insert_tail(200);
    // Insert at
    list.insert_at(300, 5);
    // Print the list
    std::cout << list.toString() << std::endl;

    // Min, Max, Sum, Average
    std::cout << "Min: " << list.min_element() << std::endl;
    std::cout << "Max: " << list.max_element() << std::endl;
    std::cout << "Sum: " << list.sum() << std::endl;
    std::cout << "Average: " << list.average() << std::endl;

    // Sort
    list.sort(2, 2);
    // Print the list
    std::cout << list.toString() << std::endl;

    // Print Sublist
    std::cout << "Sublist: " << list.subList(3, 7).toString() << std::endl;

    // Remove head
    list.remove_head();
    // Remove tail
    list.remove_tail();
    // Remove at
    list.remove_at(5);
    // Print the list
    std::cout << list.toString() << std::endl;

    std::cout << "Element at index 3 + 1: " << *(&list[3] + 1) << std::endl;
    std::cout << "Head: " << list.head() << std::endl;
    std::cout << "Tail: " << list.tail() << std::endl;

    std::cout << "Negative index: " << list[-1] << std::endl;

    // Clear the list
    list.clear();
    std::cout << "After clear: " << list.toString() << std::endl;

    // Searching
    list.insert_tail(100);
    list.insert_tail(200);
    list.insert_tail(100);
    list.insert_tail(200);
    list.insert_tail(100);
    list.insert_tail(200);
    list.insert_tail(100);
    list.insert_tail(200);
    list.insert_tail(100);
    list.insert_tail(200);
    std::cout << list.toString() << std::endl;
    std::cout << "Search 300: " << (&list.search(300) == list.none_val()) << std::endl;
    std::cout << "Search first element has value 200: " << list.search_index_firstElement(200) << std::endl;
    std::cout << "Search last element has value 200: " << list.search_index_lastElement(200) << std::endl;

    ArrayList<int> result = list.search_all_index(100);
    std::cout << "Search all index of 100: " << result.toString() << std::endl;
    return 0;
}