// Leetcode Problem for Backtracking

#ifndef BACKTRACKING_LEETCODE_PROBLEM_H
#define BACKTRACKING_LEETCODE_PROBLEM_H

// Can use all libraries
#include <bits/stdc++.h>
using namespace std;

// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
    private:
        ofstream out;
        // Index of Question

        // pointer function

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

        // 47. Permutations II
        // https://leetcode.com/problems/permutations-ii/description/
        vector<vector<int>> permuteUnique(vector<int>& nums);   

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
        private:
            struct TreeNode {
                int val;
                TreeNode *left;
                TreeNode *right;
                TreeNode() : val(0), left(nullptr), right(nullptr) {}
                TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
                TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
            };
        public:
        vector<TreeNode*> generateTrees(int n);

        // 131. Palindrome Partitioning
        // https://leetcode.com/problems/palindrome-partitioning/description/
        vector<vector<string>> partition(string s);

        // 140. Word Break II
        // https://leetcode.com/problems/word-break-ii/description/
        vector<string> wordBreak(string s, vector<string>& wordDict);

        // 212. Word Search II
        // https://leetcode.com/problems/word-search-ii/description/
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words);


        // 301. Remove Invalid Parentheses
        // https://leetcode.com/problems/remove-invalid-parentheses/description/
        vector<string> removeInvalidParentheses(string s);

        // 401. Binary Watch
        // https://leetcode.com/problems/binary-watch/description/
        vector<string> readBinaryWatch(int num);

        // 698. Partition to K Equal Sum Subsets
        // https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
        bool canPartitionKSubsets(vector<int>& nums, int k);

        // 842. Split Array into Fibonacci Sequence
        // https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/

        // 980. Unique Paths III
        // https://leetcode.com/problems/unique-paths-iii/description/
        int uniquePathsIII(vector<vector<int>>& grid);

        // 1219. Path with Maximum Gold
        // https://leetcode.com/problems/path-with-maximum-gold/description/
        int getMaximumGold(vector<vector<int>>& grid);

        // 1239. Maximum Length of a Concatenated String with Unique Characters
        // https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
        int maxLength(vector<string>& arr);

        // 1255. Maximum Score Words Formed by Letters
        // https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
        int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score);

        // 1723. Find Minimum Time to Finish All Jobs
        // https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/
        int minimumTimeRequired(vector<int>& jobs, int k);

        // 2597. The Number of Beautiful Subsets
        // https://leetcode.com/problems/the-number-of-beautiful-subsets/description/
        int beautifulSubsets(vector<int>& nums, int k);

};

#endif