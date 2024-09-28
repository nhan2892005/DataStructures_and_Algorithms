/*
Implement function 
void printArray(int n){}
to print 0, 1, 2, ..., n (n is positive integer and has no space at the end).

Please note that you can't using key work for, while, goto (even in variable names, comment).
For this exercise, we have #include <iostream> and using namespace std;
For example:

Test	                   Result
printArray(5);             0, 1, 2, 3, 4, 5
printArray(10);            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
*/

#include <iostream>
using namespace std;

void printArrayHelper(int current, int n) {
    if (current == n) {
        cout << current;
        return;
    }
    cout << current << ", ";
    printArrayHelper(current + 1, n);
}

void printArray(int n) {
    printArrayHelper(0, n);
}

int main() {
    printArray(5);
    return 0;
}