/*
Given a string s representing a sentence consisting only of a-z and A-Z and space character.
Your task is to implement a function with following prototype:
string reverseSentence(string s);
The function returns the reverse sentence of sentence s.
The testcases ensure that there is only one space character between two adjacent words, and the sentences do not begin or end with any space characters.

Note:
- The iostream library has been used and namespace std is being used. No other libraries are allowed.
- Using loop keywords (for, while, do) are not allowed, even in comments and variable names.
- You can write helper functions.

For example:

Test	
cout << reverseSentence("data structure and algorithm is scary");
Result
scary is algorithm and structure data
*/

#include <iostream>
using namespace std;

string reverseHelper(const string& s, int start, int end) {
    if (start > end) return "";

    std::string::size_type spaceIndex = s.find_last_of(' ', end);
    
    if (spaceIndex == string::npos) {
        return s.substr(start, end - start + 1);
    }

    string lastWord = s.substr(spaceIndex + 1, end - spaceIndex);
    return lastWord + " " + reverseHelper(s, start, spaceIndex - 1);
}

string reverseSentence(string s) {
    return reverseHelper(s, 0, s.length() - 1);
}

int main() {
    cout << reverseSentence("data structure and algorithm is scary");
    return 0;
}