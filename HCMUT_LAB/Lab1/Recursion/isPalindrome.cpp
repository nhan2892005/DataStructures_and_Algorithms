/*
Implement function 

bool isPalindrome(string str){}
to check if the given non empty string is palindrome, else not palindrome using recursion.

In test case, for extra point, we will have some palindrome sentences (All remaining test cases are words).

Please note that you can't using key work for, while, goto (even in variable names, comment).

For this exercise, we have #include <iostream>, #include <string.h> and using namespace std;

For example:

Test	                                                   Result
cout << isPalindrome("mom");                                1
cout << isPalindrome("do geese see god");                   1
*/

#include <iostream>
#include <string.h>
using namespace std;

bool isPalindromeHelper(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    
    if (!isalnum(str[start])) {
        return isPalindromeHelper(str, start + 1, end);
    }
    
    if (!isalnum(str[end])) {
        return isPalindromeHelper(str, start, end - 1);
    }
    
    if (tolower(str[start]) != tolower(str[end])) {
        return false;
    }
    
    return isPalindromeHelper(str, start + 1, end - 1);
}

bool isPalindrome(string str) {
    return isPalindromeHelper(str, 0, str.length() - 1);
}

int main() {
    cout << isPalindrome("mom") << endl;
    cout << isPalindrome("do geese see god") << endl;
    return 0;
}