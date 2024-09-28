/*
Function
int myArrayToInt(char* str, int n){}
takes a string str (which represents an positive decimal number), n is the number of elements in the string as arguments and returns its value.

Please note that you can't using key work for, while, goto (even in variable names, comment)

For this exercise, we have #include <iostream>, #include <string.h> and using namespace std;

For example:

Test	                                    Result
char str[] = "2020";                        2020
printf("%d", myArrayToInt(str, 4));
*/
#include <iostream>
#include <string.h>
using namespace std;

int myArrayToInt(char* str, int n) {
    if (n == 0) return 0;

    int digit = str[0] - '0';
    
    return digit * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
}

int main() {
    char str[] = "2020";
    printf("%d", myArrayToInt(str, 4));
    return 0;
}