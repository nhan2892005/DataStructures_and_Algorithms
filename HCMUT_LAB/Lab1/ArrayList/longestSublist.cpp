/*
Given an array of strings.
Your task is to implement a function with following prototype:
int longestSublist(vector<string>& words);
The function returns the length of the longest subarray where all words share the same first letter.

Note:
- The iostream and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.

For example:

Test	                                                                                Result
vector<string> words {"faction", "fight", "and", "are", "attitude"};                    3
cout << longestSublist(words);
*/

#include <iostream>
#include <vector>
using namespace std;

int longestSublist(vector<string>& words) {
    if (words.empty()) return 0;

    char currentFirstChar = words[0][0];
    int currentLength = 1;
    int maxLength = 1;

    for (int i = 1; i < words.size(); ++i) {
        if (words[i][0] == currentFirstChar) {
            currentLength++; 
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentFirstChar = words[i][0];
            currentLength = 1; 
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    return maxLength; 
}

int main() {
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words);
    return 0;
}