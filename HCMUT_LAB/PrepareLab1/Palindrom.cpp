#include <iostream>
#include <string>
using namespace std;

bool isPalindromeHelper(const string &str, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (str[left] == ' ') {
        return isPalindromeHelper(str, left + 1, right);
    }
    if (str[right] == ' ') {
        return isPalindromeHelper(str, left, right - 1);
    }
    if (str[left] != str[right]) {
        return false;
    }
    return isPalindromeHelper(str, left + 1, right - 1);
}

bool isPalindrome(const string str, int left = 0, int right = -1) {
    if (right == -1) {
        right = str.length() - 1;
    }
    if (left >= right) {
        return true;
    }
    if (str[left] == ' ') {
        return isPalindrome(str, left + 1, right);
    }
    if (str[right] == ' ') {
        return isPalindrome(str, left, right - 1);
    }
    if (str[left] != str[right]) {
        return false;
    }
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    cout << isPalindrome("mom") << "\n";                  
    cout << isPalindrome("do geese see god") << "\n";     
    cout << isPalindrome("hello") << "\n";                
    return 0;
}
