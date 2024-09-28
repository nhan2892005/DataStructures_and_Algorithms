/*
Given a string, implement function


int strLen(char* str){}
to calculate length of the string using recursion.

Please note that you can't using key work for, while, goto (even in variable names, comment).

For this exercise, we have #include <iostream> and using namespace std;



For example:

Test	                                            Result
char str[] = "Truong DH Bach Khoa";                 19
cout << strLen(str);
*/

#include <iostream>
using namespace std;

int strLen(char* str) {
    if (*str == '\0') {
        return 0; 
    }
    return 1 + strLen(str + 1);
}

int main() {
    char str[] = "Truong DH Bach Khoa";
    cout << strLen(str);
    return 0;
}