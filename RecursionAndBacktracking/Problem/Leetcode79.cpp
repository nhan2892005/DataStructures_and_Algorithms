#include "leetcode_problem.h"

bool Solution::dfs(vector<vector<char>>& board, string& word, int i, int j, int index){
    if ((j < 0 || j == board[0].size()) || (i < 0 || i == board.size()))
        return false;
    //out of range

    if (board[i][j] != word[index] || board[i][j] == '*')
        return false;
    //mark a false value if it doesn't match

    if (index == word.size() - 1)
        return true;

    const char cache = board[i][j];
    board[i][j] = '*';
    const bool isExist =dfs(board, word, i+1, j, index + 1)|| 
                        dfs(board, word, i-1, j, index + 1)||
                        dfs(board, word, i, j+1, index + 1)||
                        dfs(board, word, i, j-1, index + 1);
    board[i][j] = cache;
    return isExist;
}

bool Solution::exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (dfs(board, word, i, j, 0))
                return 1;
                
    return 0;
}