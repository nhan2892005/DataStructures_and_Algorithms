/*
Give a positive integer x, implement recursive function

void printHailstone(int number){}
to print the Hailstone Sequence of a given number upto 1 (no space at the end).

Hailstone Sequences follow these rules: 

If a number is even, divide it by 2 
If a number is odd, multiply it by 3 and add 1.
Example:

 If number = 5. 5 is odd number so next number is 5*3 + 1 = 16. 16 is even number so next number is 16/2 = 8...
 Finally, we get Hailstone sequence: 5 16 8 4 2 1.
You can find more information at: https://diendantoanhoc.net/topic/89145-d%C3%A3y-s%E1%BB%91-hailstone/

Note: Please note that you can't using key work for, while, goto (even in variable names, comment).

You can implement other recursive functions if needed.

For this exercise, we have #include <iostream> and using namespace std;

For example:

Test	                                    Result
printHailstone(32);                         32 16 8 4 2 1
*/
#include <iostream>
using namespace std;

void printHailstone(int number) {
    cout << number; 

    if (number == 1) {
        return;
    }
    if (number % 2 == 0) {
        cout << " ";
        printHailstone(number / 2);
    } else {
        cout << " "; 
        printHailstone(number * 3 + 1); 
    }
}

int main() {
    printHailstone(32);
    return 0;
}