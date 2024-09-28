/*
Given a positive number, print following a pattern without using any loop.

Input: n = 16
Output: 16, 11, 6, 1, -4, 1, 6, 11, 16 (has no space at the end)

Input: n = 10
Output: 10, 5, 0, 5, 10 (has no space at the end)

We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one add 5 until we reach n.
Note: Please note that you can't using key work for, while, goto (even in variable names, comment).

You can implement other recursive functions if needed.

For this exercise, we have #include <iostream> and using namespace std;

For example:

Test	                               Result
printPattern(14);                      14 9 4 -1 4 9 14
*/

#include <iostream>
using namespace std;

void printPatternHelper(int n, int current, bool isReturning) {
    if (current == n && isReturning) {
        cout << current;
        return;
    }
    
    cout << current << " ";

    if (!isReturning) {
        if (current > 0) {
            printPatternHelper(n, current - 5, false);
        } else {
            printPatternHelper(n, current + 5, true);
        }
    } else {
        printPatternHelper(n, current + 5, true);
    }
}

void printPattern(int n) {
    printPatternHelper(n, n, false);
}

int main() {
    printPattern(14);
    return 0;
}