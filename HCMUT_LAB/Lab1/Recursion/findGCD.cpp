/*
Give two positive integers a and b, implement function

int findGCD(int a, int b){}
to find GCD (Greatest Common Divisor) of a and b using recursion.

Please note that you can't using key work for, while, goto (even in variable names, comment).

For this exercise, we have #include <iostream> and using namespace std;


For example:

Test	                                    Result
cout << findGCD(124,32);                    4
*/
#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

int main() {
    cout << findGCD(124, 32);
    return 0;
}