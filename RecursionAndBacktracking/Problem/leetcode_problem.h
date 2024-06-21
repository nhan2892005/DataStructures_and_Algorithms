// Leetcode Problem for Backtracking

#ifndef BACKTRACKING_LEETCODE_PROBLEM_H
#define BACKTRACKING_LEETCODE_PROBLEM_H

// Can use all libraries
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
    private:
        ofstream out;
        // Index of Question

        // pointer function

        // Helper function & variable

        // Help 17
        vector<string> digitToLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        void dfs(const string& digits, int i, string&& path, vector<string>& ans);

        // Help 37
        bool isValid(vector<vector<char>>& board, int row, int col, char number);
        bool solve(vector<vector<char>> &board);

        // Help 39
        void dfs(vector<int>& candidates, 
                vector<int> &comb, 
                int i, int tot, int target, 
                vector<vector<int>> &ans);

        // Help 40
        vector<vector<int>> result;
        void comsum(vector<int> &curr, int target, int sum, vector<int> &candidates, int curInd, int n);

        // Help 46
        vector<vector<int>> result;
        vector<int> swap(vector<int> &nums, int a, int b);
        void perm(vector<int> &nums, int l, int r);

        // Help 51
        void dfs(int n, int i, vector<bool>&& cols, vector<bool>&& diag1,
           vector<bool>&& diag2, vector<string>&& board,
           vector<vector<string>>& ans);

        // Help 52
        void dfs(int n, int i, vector<bool>&& cols, vector<bool>&& diag1,
                vector<bool>&& diag2, int& ans);
        
        // Help 78
        void dfs(const vector<int>& nums, int s, vector<int>&& path, vector<vector<int>>& ans);

        // Help 79
        bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index);

        // Help 90
        void subs(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int idx);

        // Help 93
        bool isValidNumber(string s);
        bool isValidIPAddress(string s);
        vector<string> ans;
        void dfs(int idx, int dot, string& ds, string& s);

        // Help 95
        vector<TreeNode*> generateTrees(int min, int max);

        // Help 131
        void dfs(const string& s, int start, vector<string>&& path, vector<vector<string>>& ans);
        bool isPalindrome(const string& s, int l, int r);

        // Help 140
        vector<string> wordBreak(const string& s, 
                                const unordered_set<string>& wordSet,
                                unordered_map<string, vector<string>>& mem);

        // Help 1219
        vector<int> roww = {1, -1, 0, 0};
        vector<int> coll = {0, 0, -1, 1};
        int maxGold = 0;
        int dfs(vector<vector<int>>& grid, int x, int y, int n, int m);

        // Help 1239
        int dfs(const vector<int>& masks, int s, int used);
        int getMask(const string& s);

        // Help 1255
        int dfs(const vector<string>& words, 
                int s, vector<int>& count,
                const vector<int>& score);
        int useWord(const vector<string>& words, 
                    int i, vector<int>& count,
                    const vector<int>& score);
        void unuseWord( const vector<string>& words, 
                        int i, vector<int>& count);

        // Help 1863
        int dfs(const vector<int>& nums, int i, int xors);
        
    public:
        // 17. Letter Combinations of a Phone Number
        // https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
        vector<string> letterCombinations(string digits);

        // 37. Sudoku Solver
        // https://leetcode.com/problems/sudoku-solver/description/
        void solveSudoku(vector<vector<char>>& board);

        // 39. Combination Sum
        // https://leetcode.com/problems/combination-sum/description/
        vector<vector<int>> combinationSum(vector<int>& candidates, int target);

        // 40. Combination Sum II
        // https://leetcode.com/problems/combination-sum-ii/description/
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target);


        // 46. Permutations
        // https://leetcode.com/problems/permutations/description/
        vector<vector<int>> permute(vector<int>& nums); 

        // 51. N-Queens
        // https://leetcode.com/problems/n-queens/description/
        vector<vector<string>> solveNQueens(int n);

        // 52. N-Queens II
        // https://leetcode.com/problems/n-queens-ii/description/
        int totalNQueens(int n);

        // 78. Subsets
        // https://leetcode.com/problems/subsets/description/
        vector<vector<int>> subsets(vector<int>& nums);

        // 79. Word Search
        // https://leetcode.com/problems/word-search/description/
        bool exist(vector<vector<char>>& board, string word);

        // 90. Subsets II
        // https://leetcode.com/problems/subsets-ii/description/
        vector<vector<int>> subsetsWithDup(vector<int>& nums);

        // 93. Restore IP Addresses
        // https://leetcode.com/problems/restore-ip-addresses/description/
        vector<string> restoreIpAddresses(string s);

        // 95. Unique Binary Search Trees II
        // https://leetcode.com/problems/unique-binary-search-trees-ii/description/
        public:
        vector<TreeNode*> generateTrees(int n);

        // 131. Palindrome Partitioning
        // https://leetcode.com/problems/palindrome-partitioning/description/
        vector<vector<string>> partition(string s);

        // 140. Word Break II
        // https://leetcode.com/problems/word-break-ii/description/
        vector<string> wordBreak(string s, vector<string>& wordDict);

        // 1219. Path with Maximum Gold
        // https://leetcode.com/problems/path-with-maximum-gold/description/
        int getMaximumGold(vector<vector<int>>& grid);

        // 1239. Maximum Length of a Concatenated String with Unique Characters
        // https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
        int maxLength(vector<string>& arr);

        // 1255. Maximum Score Words Formed by Letters
        // https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
        int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score);

        // 1863. Sum of All Subset XOR Totals
        // https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
        int subsetXORSum(vector<int>& nums);

        // 2597. The Number of Beautiful Subsets
        // https://leetcode.com/problems/the-number-of-beautiful-subsets/description/
        int beautifulSubsets(vector<int>& nums, int k);

};

#endif