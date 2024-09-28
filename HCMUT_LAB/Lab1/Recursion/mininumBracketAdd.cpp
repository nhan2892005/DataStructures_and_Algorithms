/*
Given a string s consisting only of '(' and ')'.
Your task is to implement a function with following prototype:
int mininumBracketAdd(string s);
The function returns the mininum number of brackets needed to be inserted to s so that the brackets are balanced.

More info:
A sequence of brackets is balanced when there are no unmatched brackets.
Example: ()(()) is balanced, but ))() is not.

Note:
- The iostream library has been used and namespace std is being used. No other libraries are allowed.
- Using loop keywords (for, while, do) are not allowed, even in comments and variable names.
- You can write helper functions.

For example:

Test	                                        Result
cout << mininumBracketAdd(")))((");             5
*/

#include <iostream>
using namespace std;

void countBrackets(const string& s, int index, int& openCount, int& toAdd) {
    int n = s.length();
    
    if (index == n) return;

    if (s[index] == '(') {
        openCount++; 
    } else { 
        if (openCount > 0) {
            openCount--; 
        } else {
            toAdd++; 
        }
    }

    countBrackets(s, index + 1, openCount, toAdd); 
}

int mininumBracketAdd(string s) {
    int openCount = 0; 
    int toAdd = 0; 

    countBrackets(s, 0, openCount, toAdd); 

    return toAdd + openCount;
}

int main() {
    cout << mininumBracketAdd(")))((");
    return 0;
}