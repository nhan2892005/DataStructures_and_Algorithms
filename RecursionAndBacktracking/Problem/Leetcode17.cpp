#include "leetcode_problem.h"

// O(3^N * 4^M) time | O(3^N * 4^M) space

//digitToLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void Solution::dfs(const string& digits, int i, string&& path, vector<string>& ans) {

    // Base Case
        // If we have reached the end of the digits string, then we have a complete path
    if (i == digits.length()) {
        ans.push_back(path);
        return;
    }

    // Recursive Case
        // For each letter corresponding to the current digit, we add it to the path and move to the next digit
    for (const char letter : digitToLetters[digits[i] - '0']) {
        path.push_back(letter);
        dfs(digits, i + 1, move(path), ans);
        path.pop_back();
    }
}

vector<string> Solution::letterCombinations(string digits){
    if (digits.empty())
      return {};

    vector<string> ans;

    dfs(digits, 0, "", ans);
    return ans;
}